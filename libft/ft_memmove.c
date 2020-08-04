/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 21:36:16 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/28 00:21:02 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*mem_dest;
	const char	*mem_src;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	mem_dest = (char *)dest;
	mem_src = (char *)src;
	if (mem_src < mem_dest)
		while (n-- > 0)
			mem_dest[n] = mem_src[n];
	else
		while (i++ < n)
			mem_dest[i - 1] = mem_src[i - 1];
	return (dest);
}
