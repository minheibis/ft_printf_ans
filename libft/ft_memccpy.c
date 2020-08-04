/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:41:42 by hyuki             #+#    #+#             */
/*   Updated: 2020/07/02 18:53:53 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*mem_dest;
	unsigned char	*mem_src;
	size_t			i;

	mem_dest = (unsigned char *)dest;
	mem_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		mem_dest[i] = mem_src[i];
		if (mem_src[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
