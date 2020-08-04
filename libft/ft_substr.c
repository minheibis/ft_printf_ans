/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:24:47 by hyuki             #+#    #+#             */
/*   Updated: 2020/07/02 19:00:41 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	len_true;
	size_t	i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		return (0);
	len_true = ((len <= (len_s - start)) ? len : (len_s - start));
	if (!(sub = (char *)malloc(len_true + 1)))
		return (NULL);
	i = 0;
	while (len_true-- > 0)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
