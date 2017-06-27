/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:42:30 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:42:38 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_exit(void)
{
	exit(0);
}

void	ft_key_color(int keycode, t_all *all)
{
	if (keycode == 83)
		if (all->rgb.red > -128)
			all->rgb.red--;
	if (keycode == 84)
		if (all->rgb.green > -128)
			all->rgb.green--;
	if (keycode == 85)
		if (all->rgb.blue > -128)
			all->rgb.blue--;
	if (keycode == 86)
		if (all->rgb.red < 127)
			all->rgb.red++;
	if (keycode == 87)
		if (all->rgb.green < 127)
			all->rgb.green++;
	if (keycode == 88)
		if (all->rgb.blue < 127)
			all->rgb.blue++;
}

void	ft_shift(int keycode, t_all *all)
{
	if (keycode == 124)
		all->trans.shift_x += all->jul.step_x * 15;
	if (keycode == 123)
		all->trans.shift_x -= all->jul.step_x * 15;
	if (keycode == 126)
		all->trans.shift_y += all->jul.step_y * 15;
	if (keycode == 125)
		all->trans.shift_y -= all->jul.step_y * 15;
}

void	ft_key_help(t_all *all, int keycode)
{
	if (keycode == 4)
	{
		if (all->anim.help == 0)
			all->anim.help = 1;
		else
			all->anim.help = 0;
	}
}

int		ft_key_hook(int keycode, t_all *all)
{
	ft_key_help(all, keycode);
	if (keycode == 53)
		ft_exit();
	ft_shift(keycode, all);
	ft_key_color(keycode, all);
	if (keycode == 116)
	{
		all->m_iter += 10;
		if (all->m_iter > 2500)
			all->m_iter = 2500;
	}
	if (keycode == 121)
	{
		all->m_iter -= 10;
		if (all->m_iter < 0)
			all->m_iter = 0;
	}
	if (keycode == 27)
		ft_scale(all, all->disp.half_w, all->disp.half_h, 1.1);
	if (keycode == 24)
		ft_scale(all, all->disp.half_w, all->disp.half_h, 0.9);
	ft_key_game(keycode, all);
	ft_swap_fractal(keycode, all);
	all->anim.all = 1;
	return (0);
}
