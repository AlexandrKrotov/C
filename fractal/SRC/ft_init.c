/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:39:57 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:39:59 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	choice_fractal(t_all *all, char *str)
{
	if (ft_strcmp(str, "julia") == 0)
		init_julia(all);
	else if (ft_strcmp(str, "mask") == 0)
		init_mask(all);
	else if (ft_strcmp(str, "mandelbrot") == 0)
		init_mandelbrot(all);
	else if (ft_strcmp(str, "burn_ship") == 0)
		init_bs(all);
	else if (ft_strcmp(str, "newton") == 0)
		init_newton(all);
	else if (ft_strcmp(str, "fish") == 0)
		init_fish(all);
	else if (ft_strcmp(str, "space") == 0)
		init_space(all);
	else if (ft_strcmp(str, "sierpinski") == 0)
		init_sierpinski(all);
	else if (ft_strcmp(str, "fern") == 0)
		init_fern(all);
	else
		ft_error(1);
}

void	ft_step(t_all *all)
{
	all->jul.step_x = (all->jul.re_max - all->jul.re_min) / all->disp.d_width;
	all->jul.step_y = (all->jul.im_max - all->jul.im_min) / all->disp.d_height;
}

void	init_all(t_all *all, char *str)
{
	all->jul.re_max = 2;
	all->jul.re_min = -2;
	all->jul.im_max = 1.5;
	all->jul.im_min = -1.5;
	all->m_iter = ITER;
	all->mlx = malloc(sizeof(t_mlx));
	*all->mlx = (t_mlx){NULL, NULL, NULL, NULL, 0, 0, 0};
	all->mlx->mlx = mlx_init();
	all->mlx->wnd = mlx_new_window(all->mlx->mlx, D_WIDTH, D_HEIGHT, D_NAME);
//	ftcl_get_device(all);
	all->anim.all = 1;
	all->disp.d_width = D_WIDTH;
	all->disp.d_height = D_HEIGHT;
	all->buffer_size = (size_t)(sizeof(char) * all->disp.d_width
	* all->disp.d_height * 4);
	all->disp.half_w = all->disp.d_width / 2.0;
	all->disp.half_h = all->disp.d_height / 2.0;
	all->anim.help = 0;
	init_game(all);
}
