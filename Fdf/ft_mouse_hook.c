/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:31:46 by akrotov           #+#    #+#             */
/*   Updated: 2017/05/19 13:41:30 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_mouse_cord(int x, int y, t_all *all)
{
	all->xy.x = x;
	all->xy.y = y;
	if (all->anim.on_of == 1)
	{
		if (x > D_WIDTH)
			all->anim.right = 1;
		if (x <= D_WIDTH)
			all->anim.right = 0;
		if (x < 0)
			all->anim.left = 1;
		if (x >= 0)
			all->anim.left = 0;
		if (y > D_HEIGHT)
			all->anim.down = 1;
		if (y < D_HEIGHT)
			all->anim.down = 0;
		if (y < 0)
			all->anim.up = 1;
		if (y > 0)
			all->anim.up = 0;
		all->anim.all = 1;
	}
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == 4)
		if (all->trans.scale != 0)
		{
			all->trans.scale += 0.01;
			if (all->trans.scale <= 0)
				all->trans.scale = 0.01;
		}
	if (button == 5)
	{
		all->trans.scale -= 0.01;
		if (all->trans.scale <= 0)
			all->trans.scale = 0.001;
	}
	if (button == 1)
	{
		if (all->anim.on_of == 0)
			all->anim.on_of = 1;
		else
			all->anim.on_of = 0;
	}
	all->anim.all = 1;
	return (0);
}
