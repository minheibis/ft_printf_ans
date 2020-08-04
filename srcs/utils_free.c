/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:59:06 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/04 21:41:07 by hyuki            ###   ########.fr       */
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
