/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 07:29:05 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/03 21:54:49 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_c(unsigned char c, t_printf *p_t)
{
	if (!(p_t->o_tmp = (char *)malloc(sizeof(char) * (p_t->field + 1))))
		return (-1);
	p_t->o_tmp[p_t->field] = '\0';
	if (p_t->flag_align_left == 1)
	{
		pad_letter(0, 1, c, p_t);
		pad_letter(1, p_t->field, ' ', p_t);
	}
	else
	{
		pad_letter(1, (p_t->field - 1), ' ', p_t);
		pad_letter((p_t->field - 1), p_t->field, c, p_t);
	}
	return (0);
}
