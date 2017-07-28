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
	int 		inter;

	cam = all->cam;
	cam.z += all->trans.zoom;
	cam.x += all->trans.shift;
	ptr = all->scene;
	ray.o = (t_vertex){x + all->trans.shift, y, 0 + all->trans.zoom};
	ray.d = ft_sub_vector(ray.o, cam);
	ray.d =ft_normalized_vector(ray.d);
	ray = (t_ray){cam, ray.d};
	all->rt.t = 200000;
	inter = FALSE;
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

int			ft_shadow_ray(t_all *all, t_light *light)
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
		if (ptr->ft_inter(all, &ray, ptr))
		{
				shadow = TRUE;
				break;
		}
		ptr = ptr->next;
	}
	return (shadow);
}

void		ft_draw(t_all *all)
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

int		ft_render(t_all *all)
{
	if (all->flags.redraw == TRUE)
	{
		all->mlx->img = mlx_new_image(all->mlx->mlx, D_WIDTH, D_HEIGHT);
		all->mlx->gda = mlx_get_data_addr(all->mlx->img, &all->mlx->bpp, &all->mlx->size_line, &all->mlx->endian);
		ft_draw(all);
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd, all->mlx->img, 0, 0);
		mlx_destroy_image(all->mlx->mlx, all->mlx->img);
		all->flags.redraw = FALSE;
	}
}