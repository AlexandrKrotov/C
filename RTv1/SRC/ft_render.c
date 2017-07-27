#include "rtv1.h"

void	ft_put_color(t_all *all, int x, int y, t_rgb color)
{
	int	a;

	if ((x < (D_WIDTH) && x >= 0) && y < D_HEIGHT && y >= 0)
	{
		a = ((y * all->dsp.dsp_w + x) * 4);
		all->mlx->gda[a] = color.b;
		all->mlx->gda[a + 1] = color.g;
		all->mlx->gda[a + 2] = color.r;
		all->mlx->gda[a + 3] = color.opacity;
	}
}

int		ft_primary_ray(t_all *all, int x, int y)
{
	t_vertex	cam;
	t_objs		*ptr;
	t_ray		ray;
	t_vertex	dir;
	t_vertex 	orig;
	int 		inter;

	cam = all->cam;
	cam.z += all->trans.zoom;
	cam.x += all->trans.shift;
	ptr = all->scene;
	inter = FALSE;
	orig = (t_vertex){x + all->trans.shift, y, 0 + all->trans.zoom};
	dir = ft_sub_vector(orig, cam);
	dir =ft_normalized_vector(dir);
	ray = (t_ray){cam, dir};
	all->rt.t = 200000;
	while (ptr != NULL)
	{
		if(ptr->ft_inter(all, &ray, ptr))
		{
			ptr->ft_info(all, &ray, ptr);
			inter = TRUE;
		}
		ptr = ptr->next;
	}
	return(inter);
}

int		ft_shadow_ray(t_all *all, t_light *light)
{
	t_objs		*ptr;
	t_ray		ray;
	t_vertex	dir;
	t_vertex 	orig;
	int			shadow;

	shadow = FALSE;
	ptr = all->scene;
	orig = all->rt.inter;
	dir = ft_sub_vector(light->o, orig);
	all->rt.t = ft_get_magnitude(dir);
	dir = ft_normalized_vector(dir);
	ray = (t_ray){orig, dir};
	while (ptr != NULL)
	{
		if(ptr->ft_inter(all, &ray, ptr))
		{
				shadow = TRUE;
				break;
		}
		ptr = ptr->next;
	}
	return (shadow);
}

t_rgb	ft_phong_ambiand(t_all *all, t_rgb *color)
{
	t_rgb ret;

	ret.r = (unsigned char)(color->r * all->rt.amb_int);
	ret.g = (unsigned char)(color->g * all->rt.amb_int);
	ret.b = (unsigned char)(color->b * all->rt.amb_int);
	return (ret);
}

t_rgb	ft_phong_diffuse(t_all *all, t_vertex l, t_rgb *color)
{
	t_rgb	ret;
	double	dif_fact;

	dif_fact = fmax(0.0, ft_dot_product(ft_reverse_vector(l), all->rt.norm));
	ret.r = (unsigned char)(dif_fact * color->r);
	ret.g = (unsigned char)(dif_fact * color->g);
	ret.b = (unsigned char)(dif_fact * color->b);
	return (ret);
}

t_rgb	ft_phong_specular(t_all *all, t_vertex l, t_rgb *color)
{
	t_vertex	r;
	t_vertex	v;
	t_rgb		ret;
	double		spc_fact;

	v = ft_sub_vector(all->rt.inter, all->cam);
	v = ft_normalized_vector(v);
	r = ft_reflect_vector(l, all->rt.norm);
	r = ft_normalized_vector(r);
	spc_fact = pow(fmax(0.0, ft_dot_product(v, r)), all->rt.n);
	ret.r = (unsigned char)(255 * spc_fact);
	ret.g = (unsigned char)(255 * spc_fact);
	ret.b = (unsigned char)(255 * spc_fact);
	ret.opacity = 0;
	return (ret);
}

t_phong	ft_phong(t_all *all, t_rgb *color, t_light *light)
{
	t_vertex	l;
	t_phong		phong;

	l = ft_sub_vector(all->rt.inter, light->o);
	l = ft_normalized_vector(l);
	phong.spc = ft_phong_specular(all, l, color);
	phong.amb = ft_phong_ambiand(all, color);
	phong.dif = ft_phong_diffuse(all,l, color);

	return (phong);
}

t_rgb	ft_light_calc(t_all *all, t_rgb *color)
{
	t_light	*ptr;
	t_rgb	ret;
	int		size;

	ptr = all->light;
	size = 0;
	ret = (t_rgb){0, 0, 0, 0};
	while(ptr != NULL)
	{
		size++;
		all->flags.shadow = ft_shadow_ray(all, ptr);
		all->phong = ft_phong(all, color, ptr);
		if (!all->flags.shadow)
		{
			color->r = (unsigned char)((all->phong.dif.r + all->phong.spc.r) / 2);
			color->g = (unsigned char)((all->phong.dif.g + all->phong.spc.g) / 2);
			color->b = (unsigned char)((all->phong.dif.b + all->phong.spc.b) / 2);
			color->opacity = 0;
		}
		else
		{
			*color = all->phong.dif;
			*color = (t_rgb) {(unsigned char)(color->r * SHADOW),
							  (unsigned char)(color->g * SHADOW),
							  (unsigned char)(color->b * SHADOW), 0};
//		*color = spc;
		}
		ret = (t_rgb){ret.r + color->r, ret.g + color->g, ret.b + color->b, 0};
		ptr = ptr->next;
	}
	return ((t_rgb){(unsigned char)(ret.r / size),
					(unsigned char)(ret.g / size),
					(unsigned char)(ret.b / size)});
}

void	draw(t_all *all)
{
	int			x;
	int			y;
	int 		inter;
	t_rgb		color;

	y = all->dsp.rend_hs;
	while (y < all->dsp.rend_he)
	{
		x = all->dsp.rend_ws;
		while (x < all->dsp.rend_we)
		{
			all->rt.rgb = (t_rgb){0, 0, 0, 0};
			all->rt.n = 0;
			inter = ft_primary_ray(all, x, y);
			color = all->rt.rgb;
			if (inter == TRUE)
					color = ft_light_calc(all, &color);
			ft_put_color(all, x + all->dsp.half_w, y + all->dsp.half_h, color);
			x++;
		}
		y++;
	}
}

int	ft_render(t_all *all)
{
	if (all->flags.redraw == TRUE)
	{
		all->mlx->img = mlx_new_image(all->mlx->mlx, D_WIDTH, D_HEIGHT);
		all->mlx->gda = mlx_get_data_addr(all->mlx->img, &all->mlx->bpp, &all->mlx->size_line, &all->mlx->endian);
		draw(all);
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd, all->mlx->img, 0, 0);
		mlx_destroy_image(all->mlx->mlx, all->mlx->img);
		all->flags.redraw = FALSE;
	}
}