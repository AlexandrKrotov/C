/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 20:40:25 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/11 20:40:26 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_calc_fern(double xp, double *x, double *y)
{
	int		r;

	r = rand() % 100;
	if (r < 1)
	{
		(*x) = 0;
		(*y) = 0.19 * (*y);
	}
	else if (r < 86)
	{
		(*x) = 0.85 * (*x) + 0.04 * (*y);
		(*y) = -0.04 * xp + 0.85 * (*y) + 1.6;
	}
	else if (r < 93)
	{
		(*x) = 0.2 * (*x) - 0.26 * (*y);
		(*y) = 0.23 * xp + 0.22 * (*y) + 1.6;
	}
	else
	{
		(*x) = -0.15 * (*x) + 0.28 * (*y);
		(*y) = 0.26 * xp + 0.24 * (*y) + 0.44;
	}
}

void	fern(t_all *all)
{
	double	x;
	double	y;
	double	xp;
	int		iter;

	x = 0;
	y = 0;
	iter = 0;
	while (iter < 100000)
	{
		ft_put_color(all, (int)(all->disp.half_w + 58 * x * 1.5),
		(int)(all->disp.d_height - 58 * y * 1.5), 0x00ff00);
		xp = x;
		ft_calc_fern(xp, &x, &y);
		iter++;
	}
}
