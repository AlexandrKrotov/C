/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:37:47 by akrotov           #+#    #+#             */
/*   Updated: 2017/05/18 21:58:00 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int error)
{
	if (error == 1)
		write(1, "Invalid map name! Use: \"filename.fdf\".\n", 39);
	if (error == 2)
		write(1, "Invalid map!\n", 12);
	exit(error);
}
