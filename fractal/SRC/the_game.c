/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 21:26:39 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 21:28:27 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_key_game(int keycode, t_all *all)
{
	if (keycode == 49)
		all->fly.shot = 1;
	if (keycode == 35)
	{
		if (all->anim.sprite == 0)
			all->anim.sprite = 1;
		else
			all->anim.sprite = 0;
	}
	if (keycode == 14)
	{
		all->fly.status = ALIVE;
		all->fly.pos_enemy = 0;
		all->fly.hp_enemy = 10;
		all->fly.time_exp = 0;
	}
}

void	ft_game_shot(t_all *all)
{
	all->sprite = mlx_xpm_file_to_image(all->mlx->mlx, "IMG/cab3.xpm",
	(int *)&all->disp.d_width, (int *)&all->disp.d_height);
	if (all->fly.pos_enemy > all->disp.half_w - 150 &&
		all->fly.pos_enemy < all->disp.half_w && all->fly.status == ALIVE)
	{
		all->fly.enemy = mlx_xpm_file_to_image(all->mlx->mlx, "IMG/ej_b.xpm",
		(int *)&all->disp.d_width, (int *)&all->disp.d_height);
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd, all->fly.enemy,
		all->fly.pos_enemy, (int)(all->disp.half_h - 130));
		all->fly.hp_enemy--;
		mlx_destroy_image(all->mlx->mlx, all->fly.enemy);
	}
	all->fly.laser = mlx_xpm_file_to_image(all->mlx->mlx, "IMG/shot.xpm",
	(int *)&all->disp.d_width, (int *)&all->disp.d_height);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd, all->fly.laser, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->fly.laser);
	if (all->fly.hp_enemy <= 0)
		all->fly.status = DEAD;
	all->anim.all = 1;
}

void	ft_move_enemy(t_all *all)
{
	if (all->fly.status == ALIVE)
	{
		if (all->fly.enemy_move == RIGHT && all->fly.pos_enemy < D_WIDTH - 200)
			all->fly.pos_enemy += 5;
		else
			all->fly.enemy_move = LEFT;
		if (all->fly.enemy_move == LEFT && all->fly.pos_enemy > 100)
			all->fly.pos_enemy -= 5;
		else
			all->fly.enemy_move = RIGHT;
		all->fly.enemy = mlx_xpm_file_to_image(all->mlx->mlx, "IMG/ej.xpm",
		(int *)&all->disp.d_width, (int *)&all->disp.d_height);
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd, all->fly.enemy,
		all->fly.pos_enemy, (int)(all->disp.half_h - 130));
		mlx_destroy_image(all->mlx->mlx, all->fly.enemy);
	}
}

void	the_game(t_all *all)
{
	all->fly.cab++;
	ft_move_enemy(all);
	if (all->fly.shot == 1)
		ft_game_shot(all);
	else if (all->fly.cab % 33 == 0)
		all->sprite = mlx_xpm_file_to_image(all->mlx->mlx, "IMG/cab1.xpm",
		(int *)&all->disp.d_width, (int *)&all->disp.d_height);
	else
		all->sprite = mlx_xpm_file_to_image(all->mlx->mlx, "IMG/cab2.xpm",
		(int *)&all->disp.d_width, (int *)&all->disp.d_height);
	if (all->fly.status == DEAD && all->fly.time_exp <= 10)
	{
		all->fly.enemy = mlx_xpm_file_to_image(all->mlx->mlx, "IMG/expos.xpm",
		(int *)&all->disp.d_width, (int *)&all->disp.d_height);
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd,
		all->fly.enemy, all->fly.pos_enemy, (int)(all->disp.half_h - 130));
		mlx_destroy_image(all->mlx->mlx, all->fly.enemy);
		all->fly.time_exp++;
	}
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd,
	all->sprite, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->sprite);
	all->fly.shot = 0;
}
