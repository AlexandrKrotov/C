/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:08:52 by akrotov           #+#    #+#             */
/*   Updated: 2017/05/18 21:58:41 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel_img(t_all *all, int x, int y, t_rgb *color)
{
	int	a;

	if ((x < (D_WIDTH) && x >= 0) && y < D_HEIGHT && y >= 0)
	{
		a = (D_WIDTH * y + x) * 4;
		all->mlx->gda[a + 0] = color->r + all->grad.red + all->trans.r_color;
		all->mlx->gda[a + 1] = color->g + all->grad.green + all->trans.g_color;
		all->mlx->gda[a + 2] = color->b + all->grad.blue + all->trans.b_color;
		all->mlx->gda[a + 3] = color->opacity;
	}
}

void		ft_draw_line(t_all *all, t_line_cord *cord)
{
	cord->dx = abs(cord->x1 - cord->x0);
	cord->sx = cord->x0 < cord->x1 ? 1 : -1;
	cord->dy = -abs(cord->y1 - cord->y0);
	cord->sy = cord->y0 < cord->y1 ? 1 : -1;
	cord->err_1 = cord->dx + cord->dy;
	cord->iter = 0;
	put_pixel_img(all, cord->x1, cord->y1, cord->color1);
	while (cord->x0 != cord->x1 || cord->y0 != cord->y1)
	{
		cord->iter++;
		if (all->anim.gradient == 1)
			ft_gradient(all, cord);
		put_pixel_img(all, cord->x0, cord->y0, cord->color0);
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
}
