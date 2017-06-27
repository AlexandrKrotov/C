/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:39:44 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:39:48 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	lets_start(char *str)
{
	t_all	all;

	init_all(&all, str);
	create_img(&all);
	mlx_mouse_hook(all.mlx->wnd, ft_mouse_hook, &all);
	mlx_hook(all.mlx->wnd, 2, 3, ft_key_hook, &all);
	mlx_hook(all.mlx->wnd, 6, 1L << 6, ft_mouse_cord, &all);
	mlx_hook(all.mlx->wnd, 17, 1L << 17, ft_exit, &all);
	mlx_loop_hook(all.mlx->mlx, create_img, &all);
	mlx_loop(all.mlx->mlx);
}

int		main(int ac, char **av)
{
	pid_t	pid;

	if (ac < 2)
		ft_error(0);
	if (ac == 2)
		lets_start(av[1]);
	else if (ac == 3 && (ft_strcmp(av[1], "sierpinski") == 0
			|| ft_strcmp(av[2], "sierpinski") == 0))
	{
		pid = fork();
		if (pid < 0)
			ft_error(-1);
		else if (pid == 0)
			lets_start(av[1]);
		else
			lets_start(av[2]);
	}
	else
		ft_error(0);
	return (0);
}
