/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:55:12 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/28 00:18:56 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *mem_s1;
	unsigned char *mem_s2;

	mem_s1 = (unsigned char *)s1;
	mem_s2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*mem_s1 != *mem_s2)
			return (*mem_s1 - *mem_s2);
		mem_s1++;
		mem_s2++;
	}
	return (0);
}
