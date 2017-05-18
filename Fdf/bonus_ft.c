/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:12:59 by akrotov           #+#    #+#             */
/*   Updated: 2017/05/18 20:26:59 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void		write_lst(t_all *all)
{
	t_point_lst *ptr;
	t_point_lst *prev;

	ptr = all->map;
	while (ptr)
	{
		prev = ptr;
		while (ptr)
		{
			if (ptr->next_x != NULL)
				printf("%3d ", ptr->point.z);
			ptr = ptr->next_x;
		}
		printf("\n");
		ptr = prev->next_y;
	}
}

int			ft_draw_line_pp(t_all *all, t_line_cord *cord)
{
	cord->dx = abs(cord->x1 - cord->x0);
	cord->sx = cord->x0 < cord->x1 ? 1 : -1;
	cord->dy = -abs(cord->y1 - cord->y0);
	cord->sy = cord->y0 < cord->y1 ? 1 : -1;
	cord->err_1 = cord->dx + cord->dy;
	mlx_pixel_put(all->mlx, all->mlx->wnd, cord->x1, cord->y1, 0xffffff);
	while (cord->x0 != cord->x1 || cord->y0 != cord->y1)
	{
		mlx_pixel_put(all->mlx, all->mlx->wnd, cord->x0, cord->y0, 0xffffff);
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

void		ft_name_map(t_all *all, char **av)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = ft_strsplit(av[1], '/');
	while (split[i])
		i++;
	while (split[i - 1][j] != '.')
		j++;
	split[i - 1][j] = '\0';
	all->map_name = split[i - 1];
}

void		put_sprite(t_all *all)
{
	int w;
	int h;

	w = 150;
	h = 100;
	if (all->xy.x > D_WIDTH && all->xy.y < 0)
		all->sprite = mlx_xpm_file_to_image(all->mlx->mlx,
		"xpm/r_u.xpm", &w, &h);
	else if (all->xy.x < 0 && all->xy.y < 0)
		all->sprite = mlx_xpm_file_to_image(all->mlx->mlx,
		"xpm/l_u.xpm", &w, &h);
	else if (all->xy.x > D_WIDTH && all->xy.y > D_HEIGHT)
		all->sprite = mlx_xpm_file_to_image(all->mlx->mlx,
		"xpm/r_d.xpm", &w, &h);
	else if (all->xy.x < 0 && all->xy.y > D_HEIGHT)
		all->sprite = mlx_xpm_file_to_image(all->mlx->mlx,
		"xpm/l_d.xpm", &w, &h);
	else if (all->xy.x > D_WIDTH)
		all->sprite = mlx_xpm_file_to_image(all->mlx->mlx, "xpm/r.xpm", &w, &h);
	else if (all->xy.x < 0)
		all->sprite = mlx_xpm_file_to_image(all->mlx->mlx, "xpm/l.xpm", &w, &h);
	else if (all->xy.y > D_HEIGHT)
		all->sprite = mlx_xpm_file_to_image(all->mlx->mlx, "xpm/d.xpm", &w, &h);
	else
		all->sprite = mlx_xpm_file_to_image(all->mlx->mlx, "xpm/u.xpm", &w, &h);
}
