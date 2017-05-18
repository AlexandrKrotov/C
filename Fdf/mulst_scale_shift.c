/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mulst_scale_shift.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:44:16 by akrotov           #+#    #+#             */
/*   Updated: 2017/05/18 20:44:56 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	ft_mult_and_scale(const t_all *all, t_point_lst *lst0,
t_point_lst *lst1, t_line_cord *ret)
{
	ret->x0 = (int)(lst0->point.x * all->m_x_s_x - all->calc->shift_x);
	ret->y0 = (int)(lst0->point.y * all->m_y_s_y - all->calc->shift_y);
	ret->z0 = lst0->point.z * all->trans.deep_z;
	ret->x1 = (int)(lst1->point.x * all->m_x_s_x - all->calc->shift_x);
	ret->y1 = (int)(lst1->point.y * all->m_y_s_y - all->calc->shift_y);
	ret->z1 = lst1->point.z * all->trans.deep_z;
}

void	move_centr_scale(const t_all *all, t_line_cord *ret)
{
	ret->x0 = (int)(ret->x0 * all->trans.scale + all->calc->shift_w);
	ret->y0 = (int)(ret->y0 * all->trans.scale + all->calc->shift_h);
	ret->x1 = (int)(ret->x1 * all->trans.scale + all->calc->shift_w);
	ret->y1 = (int)(ret->y1 * all->trans.scale + all->calc->shift_h);
}

void	mouse_shift(t_all *all)
{
	if (all->anim.right == 1)
		all->trans.shift.x_shift -= 1 * all->trans.scale;
	if (all->anim.left == 1)
		all->trans.shift.x_shift += 1 * all->trans.scale;
	if (all->anim.down == 1)
		all->trans.shift.y_shift -= 1 * all->trans.scale;
	if (all->anim.up == 1)
		all->trans.shift.y_shift += 1 * all->trans.scale;
	if (all->anim.animation == 1)
		all->trans.angle_x += 0.5;
}
