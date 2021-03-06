/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:35:52 by akrotov           #+#    #+#             */
/*   Updated: 2017/05/18 21:47:53 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_ox(t_all *all, t_point_lst *lst0,
t_point_lst *lst1, t_line_cord *ret)
{
	int tmp;

	tmp = ret->y0;
	ret->y0 = ret->y0 * all->calc->cos_x + (*lst0).point.z * all->calc->sin_x;
	ret->z0 = -tmp * all->calc->sin_x + (*lst0).point.z * all->calc->cos_x;
	tmp = ret->y1;
	ret->y1 = ret->y1 * all->calc->cos_x + (*lst1).point.z * all->calc->sin_x;
	ret->z1 = -tmp * all->calc->sin_x + (*lst1).point.z * all->calc->cos_x;
}

void	ft_oy(t_all *all, t_line_cord *ret)
{
	int tmp;

	tmp = ret->x0;
	ret->x0 = ret->x0 * all->calc->cos_y + ret->z0 * all->calc->sin_y;
	ret->z0 = -tmp * all->calc->sin_y + ret->z0 * all->calc->cos_y;
	tmp = ret->x1;
	ret->x1 = ret->x1 * all->calc->cos_y + ret->z1 * all->calc->sin_y;
	ret->z1 = -tmp * all->calc->sin_y + ret->z1 * all->calc->cos_y;
}

void	ft_oz(t_all *all, t_line_cord *ret)
{
	int tmp;

	tmp = ret->x0;
	ret->x0 = ret->x0 * all->calc->cos_z - ret->y0 * all->calc->sin_z;
	ret->y0 = tmp * all->calc->sin_z + ret->y0 * all->calc->cos_z;
	tmp = ret->x1;
	ret->x1 = ret->x1 * all->calc->cos_z - ret->y1 * all->calc->sin_z;
	ret->y1 = tmp * all->calc->sin_z + ret->y1 * all->calc->cos_z;
}
