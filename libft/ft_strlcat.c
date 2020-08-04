/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:57:36 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/27 16:28:32 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dest[i] && size > 0)
	{
		i++;
		size--;
	}
	if (size > 0)
	{
		while (*src && size > 1)
		{
			dest[i++] = *src++;
			size--;
		}
		dest[i] = '\0';
	}
	while (*src++)
		i++;
	return (i);
}
