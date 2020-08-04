/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:21:11 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/27 22:40:32 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem_s;

	mem_s = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*mem_s == (unsigned char)c)
			return ((void *)mem_s);
		mem_s++;
	}
	return (0);
}
