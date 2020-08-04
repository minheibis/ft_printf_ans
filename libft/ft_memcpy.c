/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:29:02 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/27 22:33:19 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*mem_dest;
	const char	*mem_src;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	mem_dest = (char *)dest;
	mem_src = (char *)src;
	while (i < n)
	{
		mem_dest[i] = mem_src[i];
		i++;
	}
	return (dest);
}
