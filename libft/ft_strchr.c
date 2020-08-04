/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:20:29 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/28 00:27:31 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str_s;
	char	char_c;

	str_s = (char *)s;
	char_c = (char)c;
	if (c == '\0')
	{
		while (*str_s)
			str_s++;
		return (str_s);
	}
	else
	{
		while (*str_s)
			if (*str_s++ == char_c)
				return (--str_s);
	}
	return (NULL);
}
