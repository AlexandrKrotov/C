#include "rtv1.h"

void	ft_put_color(t_all *all, int x, int y)
{
	int	a;

	if ((x < (D_WIDTH) && x >= 0) && y < D_HEIGHT && y >= 0)
	{
		a = ((y * all->dsp.dsp_w + x) * 4);
		all->mlx->gda[a] = all->rt.rgb.b;
		all->mlx->gda[a + 1] = all->rt.rgb.g;
		all->mlx->gda[a + 2] = all->rt.rgb.r;
		all->mlx->gda[a + 3] = 0;
	}
}

int	ft_primary_ray(t_all *all, int x, int y)
{
	t_vertex	cam;
	t_objs		*ptr;
	t_ray		ray;
	t_vertex	dir;
	t_vertex 	orig;
	double		mv;
	int 		inter;

	cam = all->cam;
	cam.z += all->trans.zoom;
	ptr = all->scene;
	inter = FALSE;
	orig = (t_vertex){x, y, 0};
	dir = ft_sub_vector(orig, cam);
	mv = ft_get_magnitude(dir);
	dir =ft_normalized_vector(dir, mv);
	ray = (t_ray){cam, dir};
	all->rt.t = 200000;
	while (ptr != NULL)
	{
		if(ft_sphere_intersect(all, &ray, ptr))
			inter = TRUE;
		ptr = ptr->next;
	}
	return(inter);
}

int ft_shadow_ray(t_all *all)
{
	t_objs		*ptr;
	t_ray		ray;
	t_vertex	dir;
	double		mv;
	t_vertex 	orig;
	int			shadow;

	shadow = FALSE;
	ptr = all->scene;
	orig = all->rt.inter;
	dir = ft_sub_vector(all->light, orig);
	mv = ft_get_magnitude(dir);
	dir = ft_normalized_vector(dir, mv);
	ray = (t_ray){orig, dir};
	while (ptr != NULL)
	{
		if(ft_sphere_intersect(all, &ray, ptr))
		{
			shadow = TRUE;
			break;
		}
		ptr = ptr->next;
	}
	return (shadow);
}

void main_while(t_all *all)
{
	int			x;
	int			y;
	t_vertex	vec1;
	int 		shadow;
	int 		inter;
	t_rgb		test;

	y = all->dsp.rend_hs;
	while (y < all->dsp.rend_he)
	{
		x = all->dsp.rend_ws;
		while (x < all->dsp.rend_we)
		{
			all->rt.rgb = (t_rgb){0, 0, 0, 0};
			inter = ft_primary_ray(all, x, y);
			test = all->rt.rgb;
			if (inter == TRUE)
			{
				vec1 = ft_normalized_vector(all->light, ft_get_magnitude(all->light));
				all->rt.brightness = ft_dot_product(vec1, all->rt.norm);
				if (all->rt.brightness < 0)
					all->rt.brightness = 0;
				all->rt.rgb = (t_rgb){(unsigned char)(test.r * all->rt.brightness),
							   (unsigned char)(test.g * all->rt.brightness),
							   (unsigned char)(test.b * all->rt.brightness), 0};

			}
			test = all->rt.rgb;
			if (inter == TRUE)
				shadow = ft_shadow_ray(all);
			if(inter == TRUE && shadow == TRUE)
				all->rt.rgb = (t_rgb){(unsigned char)(test.r * 0.30), (unsigned char)(test.g * 0.30 ), (unsigned char)(test.b * 0.30), 0};
			ft_put_color(all, x + all->dsp.half_w, y + all->dsp.half_h);
			x++;
		}
		y++;
	}
}

int	ft_render(t_all *all)
{
	all->mlx->img = mlx_new_image(all->mlx->mlx, D_WIDTH, D_HEIGHT);
	all->mlx->gda = mlx_get_data_addr(all->mlx->img, &all->mlx->bpp, &all->mlx->size_line, &all->mlx->endian);
	main_while(all);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd, all->mlx->img, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
}


