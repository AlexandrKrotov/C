/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:03:56 by akrotov           #+#    #+#             */
/*   Updated: 2017/05/18 20:08:35 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_line_cord		*ft_create_cord(t_all *all, t_point_lst lst0, t_point_lst lst1)
{
	t_line_cord	*ret;

	ret = malloc(sizeof(t_line_cord));
	*ret = (t_line_cord){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL};
	ft_mult_and_scale(all, &lst0, &lst1, ret);
	ft_ox(all, &lst0, &lst1, ret);
	ft_oy(all, ret);
	ft_oz(all, ret);
	move_centr_scale(all, ret);
	ret->color0 = lst0.point.color;
	ret->color1 = lst1.point.color;
	return (ret);
}

void			creat_and_draw(t_all *all, t_point_lst lst0, t_point_lst lst1)
{
	t_line_cord	*cord;

	cord = ft_create_cord(all, lst0, lst1);
	ft_draw_line(all, cord);
	free(cord);
}

t_point_lst		*go_to_y(t_all *all, t_point_lst *map)
{
	t_point_lst *ret;
	int			i;

	i = 0;
	ret = map;
	while (i < all->thr_iter * all->num_op)
	{
		if (ret->next_y != NULL)
			ret = ret->next_y;
		i++;
	}
	return (ret);
}

void			*thread_drow(void *all)
{
	t_point_lst	*ptr;
	t_point_lst	*prev;
	t_all		*thr_all;
	int			i;

	thr_all = all;
	ptr = go_to_y(thr_all, thr_all->map);
	i = 0;
	while (i++ < thr_all->num_op)
	{
		if (ptr != NULL)
			prev = ptr;
		while (ptr)
		{
			if (ptr->next_x != NULL)
				creat_and_draw(all, *ptr, *ptr->next_x);
			if (ptr->next_y != NULL)
				creat_and_draw(all, *ptr, *ptr->next_y);
			if (thr_all->width == 1 && thr_all->height == 1)
				creat_and_draw(all, *ptr, *ptr);
			ptr = ptr->next_x;
		}
		if (prev->next_y != NULL)
			ptr = prev->next_y;
	}
	pthread_exit(NULL);
}

int				ft_draw_map(t_all *all)
{
	pthread_t	thread[THREAD_NUM];
	int			i;
	t_all		*thr[THREAD_NUM];

	i = 0;
	while (i < THREAD_NUM)
	{
		thr[i] = malloc(sizeof(t_all));
		*thr[i] = *all;
		thr[i]->thr_iter = i;
		pthread_create(&thread[i], NULL, thread_drow, (void *)thr[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(thread[i], NULL);
	i = 0;
	while (i < THREAD_NUM)
	{
		free(thr[i]);
		i++;
	}
	return (0);
}
