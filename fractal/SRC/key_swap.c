/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 21:51:33 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 21:51:39 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_key_swap_mand(int keycode, t_all *all)
{
	if (keycode == 18)
		init_mandelbrot(all);
	if (keycode == 19)
		init_julia(all);
	if (keycode == 20)
		init_bs(all);
}

void	ft_swap_fractal(int keycode, t_all *all)
{
	if ((keycode >= 18 && keycode <= 23)
		|| keycode == 26 || keycode == 28 || keycode == 1)
		free(all->filename);
	ft_key_swap_mand(keycode, all);
	if (keycode == 21)
		init_mask(all);
	if (keycode == 23)
		init_newton(all);
	if (keycode == 22)
		init_fish(all);
	if (keycode == 26)
		init_sierpinski(all);
	if (keycode == 28)
		init_fern(all);
	if (keycode == 1)
		init_space(all);
}
