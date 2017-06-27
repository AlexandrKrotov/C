/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:42:45 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:46:18 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_scale(t_all *all, double x, double y, double mult)
{
	double	x_mult;
	double	y_mult;

	x = all->jul.re_min + x *
	(all->jul.re_max - all->jul.re_min) / (D_WIDTH - 1);
	y = all->jul.im_min + y *
	(all->jul.im_max - all->jul.im_min) / (D_HEIGHT - 1);
	x_mult = x * (1 - mult);
	y_mult = y * (1 - mult);
	all->jul.re_max = all->jul.re_max * mult + x_mult;
	all->jul.re_min = all->jul.re_min * mult + x_mult;
	all->jul.im_max = all->jul.im_max * mult + y_mult;
	all->jul.im_min = all->jul.im_min * mult + y_mult;
}

void	mouse_shift(t_all *all)
{
	if (all->anim.m_shift == 1)
	{
		if (all->anim.right == 1)
			all->trans.shift_x += all->jul.step_x * 15;
		if (all->anim.left == 1)
			all->trans.shift_x -= all->jul.step_x * 15;
		if (all->anim.down == 1)
			all->trans.shift_y -= all->jul.step_y * 15;
		if (all->anim.up == 1)
			all->trans.shift_y += all->jul.step_y * 15;
	}
	if (all->anim.on_of == 1)
	{
		if (all->anim.right == 1)
			all->jul.c_re += 0.001;
		if (all->anim.left == 1)
			all->jul.c_re -= 0.001;
		if (all->anim.down == 1)
			all->jul.c_im -= 0.001;
		if (all->anim.up == 1)
			all->jul.c_im += 0.001;
	}
}

int		ft_mouse_cord(int x, int y, t_all *all)
{
	all->xy.x = x;
	all->xy.y = y;
	if (all->anim.on_of == 1 || all->anim.m_shift == 1)
	{
		if (x > all->disp.half_w + 50)
			all->anim.right = 1;
		if (x <= all->disp.half_w + 50)
			all->anim.right = 0;
		if (x < all->disp.half_w - 50)
			all->anim.left = 1;
		if (x >= all->disp.half_w - 50)
			all->anim.left = 0;
		if (y > all->disp.half_h + 50)
			all->anim.down = 1;
		if (y < all->disp.half_h + 50)
			all->anim.down = 0;
		if (y < all->disp.half_h - 50)
			all->anim.up = 1;
		if (y > all->disp.half_h - 50)
			all->anim.up = 0;
	}
	all->anim.all = 1;
	return (0);
}

int		ft_mouse_hook(int keycode, int x, int y, t_all *all)
{
	if (keycode == 4)
		ft_scale(all, x, y, 1.1);
	if (keycode == 5)
		ft_scale(all, x, y, 0.9);
	if (keycode == 1)
	{
		if (all->anim.on_of == 0)
			all->anim.on_of = 1;
		else
			all->anim.on_of = 0;
	}
	if (keycode == 2)
	{
		if (all->anim.m_shift == 0)
			all->anim.m_shift = 1;
		else
			all->anim.m_shift = 0;
	}
	all->anim.all = 1;
	return (0);
}
