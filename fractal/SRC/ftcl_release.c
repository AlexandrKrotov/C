/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcl_release.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:41:05 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:41:11 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ftcl_release(t_all *all, cl_context context,
		cl_command_queue *cmd_queue, cl_mem *image)
{
	int i;
	int err;

	err = clReleaseKernel(all->cl.kernel);
	check_succeeded("Release program", err);
	i = 0;
	while (i < (int)all->cl.num_devices)
	{
		clFinish(cmd_queue[i]);
		i++;
	}
	clReleaseMemObject(*image);
	i = 0;
	while (i < (int)all->cl.num_devices)
	{
		clReleaseCommandQueue(cmd_queue[i]);
		i++;
	}
	clReleaseContext(context);
}
