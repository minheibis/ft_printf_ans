/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:59:06 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/08 14:18:01 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		free_t_printf(t_printf *p_t, int rv)
{
	free(p_t->format);
	free(p_t->output);
	p_t->format = NULL;
	p_t->output = NULL;
	return (rv);
}

char	*free_strjoin(char *str1, char *str2)
{
	char	*join;

	join = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	str1 = NULL;
	str2 = NULL;
	return (join);
}

char	*free_join_output(t_printf *p_t)
{
	char	*join;
	int		len;
	int		i;
	int		j;

	len = p_t->rv + p_t->rv_tmp;
	if (!(join = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	join[len] = '\0';
	i = 0;
	while(i < p_t->rv)
	{
		join[i] = p_t->output[i];
		i++;
	}
	j = 0;
	while(i < len)
		join[i++] = p_t->o_tmp[j++];
	p_t->rv = len;
	free(p_t->output);
	free(p_t->o_tmp);
	p_t->output = NULL;
	p_t->o_tmp = NULL;
	return (join);
}
