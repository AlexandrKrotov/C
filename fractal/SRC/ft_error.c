/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 20:37:47 by akrotov           #+#    #+#             */
/*   Updated: 2017/06/10 20:40:16 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_error(int error)
{
	if (error == 0)
	{
		ft_putstr("Not work without argument!\n");
		ft_putstr("Use: ./fractal \"fractal name\"\n");
		ft_putstr("Fractals list:\n\t\t[mandelbrot]\n\t\t[julia]\n\t\t"
		"[burn_ship]\n\t\t[mask]\n\t\t[sierpinski]\n"
		"\t\t[newton]\n\t\t[fish]\n\t\t[fern]\n");
		ft_putstr("Wanna see my fork? Use \"./fractal \"sierpinski fern\"\n");
	}
	if (error == 1)
	{
		write(1, "Invalid fractal name!\n", 22);
		ft_putstr("Use: ./fractal \"fractal name\"\n");
		ft_putstr("Fractals list:\n\t\t[mandelbrot]\n\t\t[julia]\n\t\t"
		"[burn_ship]\n\t\t[mask]\n\t\t[sierpinski]\n"
		"\t\t[newton]\n\t\t[fish]\n\t\t[fern]\n");
		ft_putstr("Wanna see my fork? Use \"./fractal \"sierpinski fern\"\n");
	}
	if (error == -1)
		write(1, "Fork Error\n", 11);
	exit(error);
}
