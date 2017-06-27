#include "rtv1.h"

void	ft_put_color(t_all *all, int x, int y, int color)
{
	int	a;

	if ((x < (D_WIDTH) && x >= 0) && y < D_HEIGHT && y >= 0)
	{
		a = ((y * all->dsp.dsp_w + x) * 4);
		all->mlx->gda[a] = (char)((color & 0xFF0000) >> 16);
		all->mlx->gda[a + 1] = (char)((color & 0xFF00) >> 8);
		all->mlx->gda[a + 2] = (char)(color & 0xFF);
		all->mlx->gda[a + 3] = 0;
	}
}

void main_whail(t_all *all)
{
	int			x;
	int			y;
	t_vertex	vec1;
	t_vertex	vec2;
	t_vector	ray;

	y = 0;
	while (y < all->dsp.dsp_h)
	{
		x = 0;
		while (x < all->dsp.dsp_w)
		{
			vec1 = (t_vertex){x, y, 0};
			vec2 = (t_vertex){0, 0, 1};
			ray = (t_vector){vec1, vec2};

			double t = 200000;

			if(ft_sphere_intersect(all, &ray, &t))
				ft_put_color(all, x, y, 0x00ff00);
			else
				ft_put_color(all, x, y, 0xffffff);
			x++;
		}
		y++;
	}
}

int	ft_render(t_all *all)
{
	all->mlx->img = mlx_new_image(all->mlx->mlx, D_WIDTH, D_HEIGHT);
	all->mlx->gda = mlx_get_data_addr(all->mlx->img, &all->mlx->bpp, &all->mlx->size_line, &all->mlx->endian);
	main_whail(all);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd, all->mlx->img, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
}


