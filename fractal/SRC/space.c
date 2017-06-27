/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:45:25 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:45:51 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		addr(int x, int y, int width)
{
	return (width * y + x) * 4;
}

void	ft_draw_space(t_all *all)
{
	int		color;
	int		idx;
	int		x;
	int		y;

	y = 0;
	while (y < D_HEIGHT)
	{
		x = 0;
		while (x < D_WIDTH)
		{
			idx = addr(x, y, (int)all->disp.d_width);
			color = rand() % 10000;
			if (color > 9995)
			{
				all->mlx->gda[idx] = (char)(color * rand() % 255);
				all->mlx->gda[idx + 1] = (char)(color * rand() % 255);
				all->mlx->gda[idx + 2] = (char)(color * rand() % 255);
				all->mlx->gda[idx + 3] = 0;
			}
			x++;
		}
		y++;
	}
}
