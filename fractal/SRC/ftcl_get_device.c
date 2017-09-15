///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ftcl_get_device.c                                  :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/06/10 20:40:48 by akrotov           #+#    #+#             */
///*   Updated: 2017/06/10 20:40:49 by akrotov          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "fractal.h"
//
//void	ftcl_get_device(t_all *all)
//{
//	cl_int			err;
//	cl_device_id	cpus[16];
//	cl_uint			num_cpus;
//
//	all->cl.num_devices = 0;
//	all->cl.devices = malloc(16 * sizeof(cl_device_id));
//	err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_CPU, 16, cpus, &num_cpus);
//	check_succeeded("Getting device IDs", err);
//	err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 16,
//	all->cl.devices, &all->cl.num_devices);
//	check_succeeded("Getting device IDs", err);
//}
