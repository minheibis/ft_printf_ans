/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:19:25 by hyuki             #+#    #+#             */
/*   Updated: 2020/07/01 15:55:33 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dest, const char *src)
{
	int		k;

	k = 0;
	while (src[k] != '\0')
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = '\0';
}

char		*ft_strdup(const char *src)
{
	char	*p;
	size_t	len;

	len = ft_strlen((char *)src);
	if (!(p = (char *)malloc(len + 1)))
		return (NULL);
	ft_strcpy(p, src);
	return (p);
}
