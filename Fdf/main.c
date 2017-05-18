/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:32:22 by akrotov           #+#    #+#             */
/*   Updated: 2017/05/18 19:36:43 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	init_all(t_all *all)
{
	*all = (t_all){0};
	all->trans = (t_trans){0, 0, 0, 0, 0, 0, 0, 0};
	all->mlx = malloc(sizeof(t_mlx));
	*all->mlx = (t_mlx){0};
	all->trans.shift = (t_shift){0};
	all->mlx->mlx = mlx_init();
	all->mlx->wnd = mlx_new_window(all->mlx->mlx, D_WIDTH, D_HEIGHT, D_NAME);
	all->trans.scale = 1;
	all->mlx->endian = 0;
	all->d_width = D_WIDTH;
	all->d_height = D_HEIGHT;
	all->half_w = all->d_width / 2;
	all->half_h = all->d_height / 2;
	all->anim = (t_anim){1, 0, 0, 0, 0};
}

int		create_img(t_all *all)
{
	if (all->anim.all == 1)
	{
		mouse_shift(all);
		all->calc = malloc(sizeof(t_calc));
		*all->calc = (t_calc) {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		all->mlx->img = mlx_new_image(all->mlx, D_WIDTH, D_HEIGHT);
		all->mlx->gda = mlx_get_data_addr(all->mlx->img,
		&all->mlx->bpb, &all->mlx->size_line, &all->mlx->endian);
		ft_calc_all(all);
		ft_draw_map(all);
		mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd,
		all->mlx->img, 0, 0);
		mlx_string_put(all->mlx->mlx, all->mlx->wnd,
		10, D_HEIGHT - 20, 0x0000ff, &*all->map_name);
		if (all->anim.sprite == 1)
		{
			put_sprite(all);
			mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd,
			all->sprite, all->half_w - 125, all->half_h - 100);
			mlx_destroy_image(all->mlx->mlx, all->sprite);
		}
		mlx_destroy_image(all->mlx->mlx, all->mlx->img);
		free(all->calc);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_all all;

	init_all(&all);
	ft_parser(av, &all);
	ft_name_map(&all, av);
	all.m_x_s_x = (all.d_width / all.width) / 2.0;
	all.m_y_s_y = (all.d_height / all.height) / 2.0;
	all.num_op = (all.height / THREAD_NUM) + 1;
	write_lst(&all);
	create_img(&all);
	mlx_mouse_hook(all.mlx->wnd, ft_mouse_hook, &all);
	mlx_hook(all.mlx->wnd, 2, 3, ft_key_hook, &all);
	mlx_hook(all.mlx->wnd, 6, (1L << 6), ft_mouse_cord, &all);
	mlx_loop_hook(all.mlx->mlx, create_img, &all);
	mlx_loop(all.mlx->mlx);
	return (0);
}
