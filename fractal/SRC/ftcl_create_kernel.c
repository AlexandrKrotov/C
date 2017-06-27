/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcl_create_kernel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:40:28 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:40:30 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ftcl_init_part1(t_all *all, cl_context context, cl_mem *image)
{
	cl_double	step_x;
	cl_double	step_y;
	cl_double	re_min;
	cl_double	im_min;

	all->cl.kernel = load_kernel_from_file(context, all->filename);
	all->cl.err = clSetKernelArg(all->cl.kernel, 0, sizeof(cl_mem), image);
	check_succeeded("Setting all->cl.kernel arg", all->cl.err);
	step_x = all->jul.step_x;
	all->cl.err = clSetKernelArg(all->cl.kernel, 1, sizeof(cl_double), &step_x);
	check_succeeded("Setting all->cl.kernel arg", all->cl.err);
	step_y = all->jul.step_y;
	all->cl.err = clSetKernelArg(all->cl.kernel, 2, sizeof(cl_double), &step_y);
	check_succeeded("Setting all->cl.kernel arg", all->cl.err);
	re_min = all->jul.re_min;
	all->cl.err = clSetKernelArg(all->cl.kernel, 3, sizeof(cl_double), &re_min);
	check_succeeded("Setting all->cl.kernel arg", all->cl.err);
	im_min = all->jul.im_min;
	all->cl.err = clSetKernelArg(all->cl.kernel, 4, sizeof(cl_double), &im_min);
	check_succeeded("Setting all->cl.kernel arg", all->cl.err);
}

void	ftcl_init_part2(t_all *all)
{
	cl_double	sh_y;
	cl_double	sh_x;

	sh_x = all->trans.shift_x;
	all->cl.err = clSetKernelArg(all->cl.kernel, 5, sizeof(cl_double), &sh_x);
	check_succeeded("Setting all->cl.kernel arg", all->cl.err);
	sh_y = all->trans.shift_y;
	all->cl.err = clSetKernelArg(all->cl.kernel, 6, sizeof(cl_double), &sh_y);
	check_succeeded("Setting all->cl.kernel arg", all->cl.err);
}

void	ftcl_init_part3(t_all *all)
{
	cl_int	red;
	cl_int	green;
	cl_int	blue;

	red = all->rgb.red;
	all->cl.err = clSetKernelArg(all->cl.kernel, 8, sizeof(cl_int), &red);
	check_succeeded("Setting kernel arg", all->cl.err);
	green = all->rgb.green;
	all->cl.err = clSetKernelArg(all->cl.kernel, 9, sizeof(cl_int), &green);
	check_succeeded("Setting kernel arg", all->cl.err);
	blue = all->rgb.blue;
	all->cl.err = clSetKernelArg(all->cl.kernel, 10, sizeof(cl_int), &blue);
	check_succeeded("Setting kernel arg", all->cl.err);
}

void	ftcl_put_argv(t_all *all, cl_context context, cl_mem *image)
{
	cl_int		m_iter;
	cl_double	c_re;
	cl_double	c_im;

	ftcl_init_part1(all, context, image);
	m_iter = all->m_iter;
	all->cl.err = clSetKernelArg(all->cl.kernel, 7, sizeof(cl_int), &m_iter);
	check_succeeded("Setting kernel arg", all->cl.err);
	ftcl_init_part2(all);
	ftcl_init_part3(all);
	c_re = all->jul.c_re;
	all->cl.err = clSetKernelArg(all->cl.kernel, 11, sizeof(cl_double), &c_re);
	check_succeeded("Setting all->cl.kernel arg", all->cl.err);
	c_im = all->jul.c_im;
	all->cl.err = clSetKernelArg(all->cl.kernel, 12, sizeof(cl_double), &c_im);
	check_succeeded("Setting all->cl.kernel arg", all->cl.err);
}
