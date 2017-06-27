/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:41:44 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:41:58 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_sierpinski(t_all *all)
{
	all->filename = ft_strdup("sierpinski");
	all->anim.all = 1;
}

void	init_fern(t_all *all)
{
	all->filename = ft_strdup("fern");
	all->anim.all = 1;
}

void	init_mask(t_all *all)
{
	all->filename = ft_strdup("Kernel/mask.cl");
	all->anim.all = 1;
	all->rgb.red = 3;
	all->rgb.green = 9;
	all->rgb.blue = 0;
	all->m_iter = 100;
	all->trans.shift_x = 0;
	all->trans.shift_y = 0;
	all->jul.re_max = 1.5;
	all->jul.re_min = -1.5;
	all->jul.im_max = 1.2;
	all->jul.im_min = -1.2;
	all->jul.c_re = 0;
	all->jul.c_im = 0;
}

void	init_space(t_all *all)
{
	all->filename = ft_strdup("space");
	all->anim.all = 1;
	all->rgb.red = 3;
	all->rgb.green = 9;
	all->rgb.blue = 3;
}

void	init_fish(t_all *all)
{
	all->filename = ft_strdup("Kernel/fish.cl");
	all->anim.all = 1;
	all->trans.shift_x = -1;
	all->trans.shift_y = 0;
	all->jul.re_max = 2;
	all->jul.re_min = -2;
	all->jul.im_max = 1.5;
	all->jul.im_min = -1.5;
	all->rgb.red = 11;
	all->rgb.green = 2;
	all->rgb.blue = 4;
	all->m_iter = 300;
	all->jul.c_re = -0.7;
	all->jul.c_re = 0;
	all->jul.c_im = 0;
}
