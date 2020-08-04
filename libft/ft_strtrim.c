/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:43:14 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/29 17:25:01 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_ans;
	size_t	ans_len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (*s1 != '\0' && ft_strchr(set, *s1) != NULL)
		s1++;
	ans_len = ft_strlen(s1) - 1;
	while (ans_len > 0 && ft_strchr(set, s1[ans_len]) != NULL)
		ans_len--;
	if (!(s1_ans = ft_substr(s1, 0, ans_len + 1)))
		return (NULL);
	return (s1_ans);
}
