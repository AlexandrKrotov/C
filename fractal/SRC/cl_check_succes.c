///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   cl_check_succes.c                                  :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2017/06/11 19:01:56 by akrotov           #+#    #+#             */
///*   Updated: 2017/06/11 19:02:00 by akrotov          ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "fractal.h"
//
//void	ftcl_check_part1(cl_int err)
//{
//	if (err == -1)
//		ft_putstr("Device not found\n");
//	else if (err == -2)
//		ft_putstr("Device not available\n");
//	else if (err == -3)
//		ft_putstr("Compiler not available\n");
//	else if (err == -4)
//		ft_putstr("Memory object allocation failure\n");
//	else if (err == -5)
//		ft_putstr("Out of resources\n");
//	else if (err == -6)
//		ft_putstr("Out of host memory\n");
//	else if (err == -7)
//		ft_putstr("Profiling info not available\n");
//	else if (err == -8)
//		ft_putstr("Memory copy overlap\n");
//	else if (err == -9)
//		ft_putstr("Image format mismatch\n");
//	else if (err == -10)
//		ft_putstr("Image format not supported\n");
//}
//
//void	ftcl_check_part2(cl_int err)
//{
//	if (err == -11)
//		ft_putstr("Build program failure\n");
//	else if (err == -12)
//		ft_putstr("Map failure\n");
//	else if (err == -30)
//		ft_putstr("Invalid value\n");
//	else if (err == -31)
//		ft_putstr("Invaid device type\n");
//	else if (err == -32)
//		ft_putstr("Invalid platform\n");
//	else if (err == -33)
//		ft_putstr("Invalid device\n");
//	else if (err == -34)
//		ft_putstr("Invalid context\n");
//	else if (err == -35)
//		ft_putstr("Invalid queue properties\n");
//	else if (err == -36)
//		ft_putstr("Invalid command queue\n");
//	else if (err == -37)
//		ft_putstr("Invalid host pointer\n");
//	else if (err == -38)
//		ft_putstr("Invalid memory object\n");
//	else if (err == -39)
//		ft_putstr("Invalid image format descriptor\n");
//}
//
//void	ftcl_check_part3(cl_int err)
//{
//	if (err == -40)
//		ft_putstr("Invalid image size\n");
//	else if (err == -41)
//		ft_putstr("Invalid sampler\n");
//	else if (err == -42)
//		ft_putstr("Invalid binary\n");
//	else if (err == -43)
//		ft_putstr("Invalid build options\n");
//	else if (err == -44)
//		ft_putstr("Invalid program\n");
//	else if (err == -45)
//		ft_putstr("Invalid program executable\n");
//	else if (err == -46)
//		ft_putstr("Invalid kernel name\n");
//	else if (err == -47)
//		ft_putstr("Invalid kernel defintion\n");
//	else if (err == -48)
//		ft_putstr("Invalid kernel\n");
//	else if (err == -49)
//		ft_putstr("Invalid argument index\n");
//	else if (err == -50)
//		ft_putstr("Invalid argument value\n");
//}
//
//void	ftcl_check_part4(cl_int err)
//{
//	if (err == -51)
//		ft_putstr("Invalid argument size\n");
//	else if (err == -52)
//		ft_putstr("Invalid kernel arguments\n");
//	else if (err == -53)
//		ft_putstr("Invalid work dimension\n");
//	else if (err == -54)
//		ft_putstr("Invalid work group size\n");
//	else if (err == -55)
//		ft_putstr("Invalid work item size\n");
//	else if (err == -56)
//		ft_putstr("Invalid global offset\n");
//	else if (err == -57)
//		ft_putstr("Invalid event wait list\n");
//	else if (err == -58)
//		ft_putstr("Invalid event\n");
//	else if (err == -59)
//		ft_putstr("Invalid operation\n");
//	else if (err == -60)
//		ft_putstr("Invalid GL object\n");
//	else if (err == -61)
//		ft_putstr("Invalid buffer size\n");
//}
//
//void	check_succeeded(char *message, cl_int err)
//{
//	if (err != CL_SUCCESS)
//	{
//		ft_putstr(message);
//		if (err < 0)
//		{
//			if (err >= -10)
//				ftcl_check_part1(err);
//			else if (err < -10 && err >= -39)
//				ftcl_check_part2(err);
//			else if (err < -39 && err >= -50)
//				ftcl_check_part3(err);
//			else if (err < -50 && err >= -61)
//				ftcl_check_part4(err);
//			else if (err == -62)
//				ft_putstr("Invalid mip level\n");
//			else if (err == -63)
//				ft_putstr("Invalid global work size\n");
//		}
//		assert(0);
//	}
//}
