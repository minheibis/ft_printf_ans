/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:53:16 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/28 20:54:09 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str_s;
	char	char_c;
	int		len_s;

	str_s = (char *)s;
	char_c = (char)c;
	len_s = ft_strlen(str_s);
	str_s += (len_s - 1);
	if (c == '\0')
		return (++str_s);
	while (len_s-- > 0)
	{
		if (*str_s == char_c)
			return (str_s);
		str_s--;
	}
	return (NULL);
}
