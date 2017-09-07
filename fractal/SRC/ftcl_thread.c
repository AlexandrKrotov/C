///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ftcl_thread.c                                      :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/06/10 20:41:18 by akrotov           #+#    #+#             */
///*   Updated: 2017/06/10 20:41:28 by akrotov          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "fractal.h"
//
//void	ftcl_thread(t_all *all, cl_command_queue *cmd_queue, cl_mem *image)
//{
//	int		i;
//	int		err;
//	size_t	device_work_size[2];
//	size_t	device_work_offset[2];
//	size_t	offset;
//
//	device_work_size[0] = (size_t)all->disp.d_width;
//	device_work_size[1] = (size_t)(all->disp.d_height / all->cl.num_devices);
//	i = 0;
//	while (i < (int)all->cl.num_devices)
//	{
//		device_work_offset[0] = 0;
//		device_work_offset[1] = device_work_size[1] * i;
//		offset = (size_t)(device_work_offset[1] * 4 * all->disp.d_width);
//		err = clEnqueueNDRangeKernel(cmd_queue[i], all->cl.kernel, 2,
//		device_work_offset, device_work_size, NULL, 0, NULL, NULL);
//		check_succeeded("Running kernel", err);
//		err = clEnqueueReadBuffer(cmd_queue[i], *image, CL_FALSE, offset,
//		all->buffer_size / all->cl.num_devices, all->mlx->gda, 0, NULL, NULL);
//		check_succeeded("Reading buffer", err);
//		i++;
//	}
//}
