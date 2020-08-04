/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:57:17 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/04 21:42:12 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pad_letter(int start, int end, char c, t_printf *p_t)
{
	while (start < end)
	{
		p_t->o_tmp[start] = c;
		start++;
	}
	return (0);
}

int		pad_str(int start, char *str, t_printf *p_t)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		p_t->o_tmp[start] = str[i];
		start++;
		i++;
	}
	return (0);
}
