///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   cl.c                                               :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/06/10 20:40:06 by akrotov           #+#    #+#             */
///*   Updated: 2017/06/10 20:40:07 by akrotov          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "fractal.h"
//
//void	ft_opencl(t_all *all)
//{
//	cl_int	err;
//	cl_mem	image;
//	int		i;
//
//	all->cl.context = clCreateContext(0, all->cl.num_devices, all->cl.devices,
//	NULL, NULL, &err);
//	check_succeeded("Creating context", err);
//	i = 0;
//	while (i < (int)all->cl.num_devices)
//	{
//		all->cl.cmd_queue[i] = clCreateCommandQueue(all->cl.context,
//		all->cl.devices[i], 0, &err);
//		check_succeeded("Creating command queue", err);
//		i++;
//	}
//	image = clCreateBuffer(all->cl.context, CL_MEM_WRITE_ONLY, all->buffer_size,
//	NULL, &err);
//	check_succeeded("Creating buffer", err);
//	ftcl_put_argv(all, all->cl.context, &image);
//	ftcl_thread(all, all->cl.cmd_queue, &image);
//	ftcl_release(all, all->cl.context, all->cl.cmd_queue, &image);
//}
