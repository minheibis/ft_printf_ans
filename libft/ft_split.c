/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:38:51 by hyuki             #+#    #+#             */
/*   Updated: 2020/07/02 18:45:54 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_w_num(char *str, char c)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && *str == c)
			str++;
		if (*str != '\0' && *str != c)
		{
			while (*str != '\0' && *str != c)
				str++;
			count++;
		}
	}
	return (count);
}

static int	len_sp(char *str, char c)
{
	int i;

	i = 0;
	while (*str != '\0' && *str == c)
		str++;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static void	*ft_free_all(char **answer, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(answer[j]);
	free(answer);
	return (NULL);
}

char		**ft_split(const char *str, char c)
{
	char	**answer;
	int		i;
	int		j;
	int		w_num;
	int		w_len;

	w_num = c_w_num((char *)str, c);
	if (!(answer = (char **)malloc(sizeof(char *) * (w_num + 1))))
		return (NULL);
	i = 0;
	while (i < w_num)
	{
		w_len = len_sp((char *)str, c);
		while (*str != '\0' && *str == c)
			str++;
		if (!(answer[i] = (char *)malloc(sizeof(char) * (w_len + 1))))
			return (ft_free_all(answer, i));
		j = 0;
		while (j < w_len)
			answer[i][j++] = *(str++);
		answer[i++][j] = '\0';
	}
	answer[i] = NULL;
	return (answer);
}
