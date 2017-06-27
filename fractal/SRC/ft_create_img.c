/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 22:33:26 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 22:33:30 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_put_color(t_all *all, int x, int y, int color)
{
	int	a;

	if ((x < (D_WIDTH) && x >= 0) && y < D_HEIGHT && y >= 0)
	{
		a = (int)((y * all->disp.d_width + x) * 4);
		all->mlx->gda[a] = (char)((color & 0xFF0000) >> 16);
		all->mlx->gda[a + 1] = (char)((color & 0xFF00) >> 8);
		all->mlx->gda[a + 2] = (char)(color & 0xFF);
		all->mlx->gda[a + 3] = 0;
	}
}

void	ft_call_help(t_all *all)
{
	all->help = mlx_xpm_file_to_image(all->mlx->mlx, "IMG/help.xpm",
	(int *)&all->disp.d_width, (int *)&all->disp.d_height);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd, all->help, 0, 0);
	mlx_destroy_image(all->mlx->mlx, all->help);
}

void	ft_change_image(t_all *all)
{
	if (ft_strcmp(all->filename, "sierpinski") == 0)
		serpinski(all);
	else if (ft_strcmp(all->filename, "fern") == 0)
		fern(all);
	else if (ft_strcmp(all->filename, "space") == 0)
		ft_draw_space(all);
	else
		ft_opencl(all);
}

int		create_img(t_all *all)
{
	ft_step(all);
	mouse_shift(all);
	all->mlx->img = mlx_new_image(all->mlx, D_WIDTH, D_HEIGHT);
	all->mlx->gda = mlx_get_data_addr(all->mlx->img, &all->mlx->bpb,
	&all->mlx->size_line, &all->mlx->endian);
	all->m.zx = (all->trans.scale * all->disp.half_w);
	all->m.zy = (all->trans.scale * all->disp.half_h);
	ft_change_image(all);
	mlx_put_image_to_window(all->mlx->mlx, all->mlx->wnd, all->mlx->img, 0, 0);
	if (all->anim.sprite == 1)
		the_game(all);
	if (all->anim.help == 0)
		mlx_string_put(all->mlx->mlx, all->mlx->wnd, 6, D_HEIGHT - 20,
	0xfffffff, "Help: \"H\"");
	else
		ft_call_help(all);
	mlx_destroy_image(all->mlx->mlx, all->mlx->img);
	mlx_string_put(all->mlx->mlx, all->mlx->wnd, D_WIDTH - 50, D_HEIGHT - 20,
	0x00fff00, ft_itoa(all->m_iter));
	all->anim.all = 0;
	return (0);
}
