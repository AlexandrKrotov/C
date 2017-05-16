#include "FdF.h"

void	write_lst(t_all *all)
{
	t_point_lst *ptr;
	t_point_lst *prev;

	ptr = all->map;
	while(ptr)
	{
		prev = ptr;
		while(ptr)
		{
			if (ptr->next_x != NULL)
				printf("%3d ", ptr->point.z);
			ptr = ptr->next_x;
		}
		printf("\n");
		ptr = prev->next_y;
	}
}

/*
 *PUT_PIXELS
*/
int ft_draw_line_pp(t_all *all, t_line_cord *cord)
{
	cord->dx = abs(cord->x1 - cord->x0);
	cord->sx = cord->x0 < cord->x1 ? 1 : -1;
	cord->dy = -abs(cord->y1 - cord->y0);
	cord->sy = cord->y0 < cord->y1 ? 1 : -1;
	cord->err_1 = cord->dx + cord->dy;

	mlx_pixel_put(all->mlx, all->mlx->wnd, cord->x1, cord->y1, 0xffffff);
	while (cord->x0 != cord->x1 || cord->y0 != cord->y1)
	{
		mlx_pixel_put(all->mlx, all->mlx->wnd, cord->x0 , cord->y0, 0xffffff);
		cord->err_2 = 2 * cord->err_1;
		if (cord->err_2 >= cord->dy)
		{
			cord->err_1 += cord->dy;
			cord->x0 += cord->sx;
		}
		if (cord->err_2 <= cord->dx)
		{
			cord->err_1 += cord->dx;
			cord->y0 += cord->sy;
		}
	}
	return (0);
}

void	ft_name_map(t_all *all, char **av)
{
	char **split;
	int i;
	int j;

	i = 0;
	j = 0;

	split = ft_strsplit(av[1], '/');
	while (split[i])
		i++;
	while (split [i - 1][j] != '.')
		j++;
	split[i - 1][j] = '\0';
	all->map_name = split[i - 1];
}