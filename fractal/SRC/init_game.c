/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:42:17 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:42:21 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_game(t_all *all)
{
	all->fly.cab = 0;
	all->fly.pos_enemy = 0;
	all->fly.enemy_move = RIGHT;
	all->fly.hp_enemy = 10;
	all->fly.status = HIDE;
	all->fly.time_exp = 0;
	all->trans.scale = 1;
}
