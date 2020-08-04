/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 07:32:42 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/04 21:42:28 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_s(char *s, t_printf *p_t)
{
	int	len;
	int	s_len;

	s_len = ft_strlen(s);
	len = ((s_len > p_t->field) ? s_len : p_t->field);
	if (!(p_t->o_tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	p_t->o_tmp[len] = '\0';
	set_s_inside(s, s_len, len, p_t);
	return (0);
}

int		set_s_inside(char *s, int s_len, int len, t_printf *p_t)
{
	if (p_t->flag_align_left == 1)
	{
		pad_str(0, s, p_t);
		pad_letter(s_len, len, ' ', p_t);
	}
	else
	{
		pad_letter(0, (len - s_len), ' ', p_t);
		pad_str((len - s_len), s, p_t);
	}
	return (0);
}
