/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:42:02 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:42:10 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_mandelbrot(t_all *all)
{
	all->filename = ft_strdup("Kernel/mandelbrot.cl");
	all->anim.all = 1;
	all->trans.shift_x = -0.5;
	all->trans.shift_y = 0;
	all->jul.re_max = 1.5;
	all->jul.re_min = -1.5;
	all->jul.im_max = 1.2;
	all->jul.im_min = -1.2;
	all->rgb.red = 3;
	all->rgb.green = 1;
	all->rgb.blue = 0;
	all->m_iter = 300;
	all->jul.c_re = -0.7;
	all->jul.c_re = 0;
	all->jul.c_im = 0;
}

void	init_julia(t_all *all)
{
	all->filename = ft_strdup("Kernel/julia.cl");
	all->anim.all = 1;
	all->trans.shift_x = 0;
	all->trans.shift_y = 0;
	all->jul.re_max = 1.5;
	all->jul.re_min = -1.5;
	all->jul.im_max = 1.2;
	all->jul.im_min = -1.2;
	all->rgb.red = 1;
	all->rgb.green = 1;
	all->rgb.blue = 9;
	all->m_iter = 500;
	all->jul.c_re = 0;
	all->jul.c_im = 0;
}

void	init_bs(t_all *all)
{
	all->filename = ft_strdup("Kernel/burn_ship.cl");
	all->anim.all = 1;
	all->trans.shift_x = -0.5;
	all->trans.shift_y = 0.5;
	all->jul.re_max = 1.5;
	all->jul.re_min = -1.5;
	all->jul.im_max = 1.2;
	all->jul.im_min = -1.2;
	all->rgb.red = 1;
	all->rgb.green = 3;
	all->rgb.blue = 8;
	all->m_iter = 500;
	all->jul.c_re = 0;
	all->jul.c_im = 0;
}

void	init_newton(t_all *all)
{
	all->filename = ft_strdup("Kernel/newton.cl");
	all->anim.all = 1;
	all->rgb.red = 7;
	all->rgb.green = -11;
	all->rgb.blue = -2;
	all->m_iter = 155;
	all->trans.shift_x = 0;
	all->trans.shift_y = 0;
	all->jul.re_max = 1.5;
	all->jul.re_min = -1.5;
	all->jul.im_max = 1.2;
	all->jul.im_min = -1.2;
	all->jul.c_re = 0;
	all->jul.c_im = 0;
}
