/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:33:07 by akrotov           #+#    #+#             */
/*   Updated: 2017/05/18 22:07:42 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_axis(int keycode, t_all *all)
{
	if (keycode == 12)
		all->trans.angle_z -= 1.0;
	if (keycode == 14)
		all->trans.angle_z += 1.0;
	if (keycode == 13)
		all->trans.angle_x -= 1.0;
	if (keycode == 1)
		all->trans.angle_x += 1.0;
	if (keycode == 2)
		all->trans.angle_y -= 1.0;
	if (keycode == 0)
		all->trans.angle_y += 1.0;
}

void	ft_shift(int keycode, t_all *all)
{
	if (keycode == 124)
		all->trans.shift.x_shift += 10;
	if (keycode == 123)
		all->trans.shift.x_shift -= 10;
	if (keycode == 125)
		all->trans.shift.y_shift += 10;
	if (keycode == 126)
		all->trans.shift.y_shift -= 10;
	if (keycode == 6)
		all->trans.deep_z += 5;
	if (keycode == 7)
		all->trans.deep_z -= 5;
}

void	ft_key_color(int keycode, t_all *all)
{
	if (keycode == 83)
		if (all->trans.r_color > -128)
			all->trans.r_color--;
	if (keycode == 84)
		if (all->trans.g_color > -128)
			all->trans.g_color--;
	if (keycode == 85)
		if (all->trans.b_color > -128)
			all->trans.b_color--;
	if (keycode == 86)
		if (all->trans.r_color < 127)
			all->trans.r_color++;
	if (keycode == 87)
		if (all->trans.g_color < 127)
			all->trans.g_color++;
	if (keycode == 88)
		if (all->trans.b_color < 127)
			all->trans.b_color++;
}

void	ft_key_clear_and_scale(int keycode, t_all *all)
{
	if (keycode == 24)
	{
		all->trans.scale += 0.05;
		if (all->trans.scale <= 0)
			all->trans.scale = 0.001;
	}
	if (keycode == 27)
	{
		all->trans.scale -= 0.05;
		if (all->trans.scale <= 0)
			all->trans.scale = 0.001;
	}
	if (keycode == 49)
	{
		all->trans.angle_x = 0;
		all->trans.angle_y = 0;
		all->trans.angle_z = 0;
		all->trans.shift.x_shift = 0;
		all->trans.shift.y_shift = 0;
		all->trans.scale = 1;
		all->trans.r_color = 0;
		all->trans.g_color = 0;
		all->trans.b_color = 0;
	}
}

int		ft_key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
		exit(0);
	ft_shift(keycode, all);
	ft_key_axis(keycode, all);
	ft_key_color(keycode, all);
	ft_key_clear_and_scale(keycode, all);
	switcher(keycode, all);
	all->anim.all = 1;
	return (0);
}
