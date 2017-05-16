/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:49:47 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/08 19:49:50 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_wcpy(char *src, char c, size_t w_len)
{
	char	*ptr;
	char	*ret;

	ret = NULL;
	ptr = malloc(sizeof(char) * w_len + 1);
	if (ptr != NULL)
	{
		ret = ptr;
		while (*src != c)
		{
			*ptr = *src;
			src++;
			ptr++;
		}
		*ptr = '\0';
	}
	return (ret);
}

static char	*move_to(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str_arr;
	char	*ptr;
	size_t	wc;
	size_t	i;
	size_t	w_len;

	i = 0;
	wc = ft_word_count(s, c);
	str_arr = malloc(sizeof(char *) * (wc + 1));
	if (str_arr != NULL)
	{
		str_arr[wc] = 0;
		while (i < wc)
		{
			w_len = 0;
			s = move_to((char *)s, c);
			if (*s != c)
				ptr = (char *)s;
			while (*(s)++ != c)
				w_len++;
			str_arr[i] = ft_wcpy(ptr, c, w_len);
			i++;
		}
	}
	return (str_arr);
}
