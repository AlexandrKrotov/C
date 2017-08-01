/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 13:17:38 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/15 13:29:45 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	lets_start(void)
{
	t_all	all;

	init_all(&all);
	ft_create_obj_lst(&all);
	ft_create_light_lst(&all);
	ft_render(&all);
	mlx_mouse_hook(all.mlx->wnd, ft_mouse_hook, &all);
	mlx_hook(all.mlx->wnd, 2, 3, ft_key_hook, &all);
	mlx_hook(all.mlx->wnd, 6, 1L << 6, ft_mouse_cord, &all);
	mlx_hook(all.mlx->wnd, 17, 1L << 17, ft_exit, NULL);
	mlx_loop_hook(all.mlx->mlx, ft_render, &all);
	mlx_loop(all.mlx->mlx);
}

int		main(int ac, char **av)
{
	char c = 127;
	unsigned char v;
	v = (unsigned char)(c + 128);
	printf("%d", v);
	lets_start();
	return (0);
}
