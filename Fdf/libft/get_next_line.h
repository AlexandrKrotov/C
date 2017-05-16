/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:48:54 by akrotov           #+#    #+#             */
/*   Updated: 2017/03/14 19:15:37 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 1000

typedef struct				s_fd_and_rest
{
	int						fd;
	char					temp[BUFF_SIZE + 1];
	struct s_fd_and_rest	*next;
}							t_fd_and_rest;

int							get_next_line(int fd, char **str);

typedef struct				s_ret
{
	int						ret_r;
	size_t					ret_c;
}							t_ret;

#endif
