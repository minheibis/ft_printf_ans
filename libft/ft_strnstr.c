/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:57:18 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/28 00:32:56 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	char	*big_str;
	size_t	little_len;

	big_str = (char *)big;
	little_len = ft_strlen((char *)little);
	if (little_len == 0)
		return (big_str);
	while (*big_str != '\0' && len-- >= little_len)
	{
		i = 0;
		while (big_str[i] == little[i])
		{
			if (little[i + 1] == '\0')
				return (big_str);
			i++;
		}
		big_str++;
	}
	return (0);
}
