/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 07:29:05 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/08 12:21:37 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_c(unsigned char c, t_printf *p_t)
{
	int	len;

	if (c == '\0')
	{
		if (set_c_0(p_t) == -1)
			return (-1);
	}
	else
	{
		len = set_len_c(p_t);
		if (!(p_t->o_tmp = (char *)malloc(sizeof(char) * (len + 1))))
			return (-1);
		p_t->o_tmp[len] = '\0';
		set_c_inside(c, len, p_t);
	}
	return (0);
}

int		set_c_0(t_printf *p_t)
{
	int	len;

	if (p_t->field <= 1)
		len = 1;
	else
		len = p_t->field - 1;
	if (!(p_t->o_tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	p_t->o_tmp[len] = '\0';
	pad_letter(0, len, ' ', p_t);
	p_t->rv += 1;
	return (0);
}

int		set_len_c(t_printf *p_t)
{
	int	len;

	if (p_t->field == -1 && p_t->precision == -1)
		len = 1;
	else if (p_t->field == -1 && p_t->precision != -1)
		len = 1;
	else if (p_t->field != -1 && p_t->precision == -1)
		len = p_t->field;
	else
		len = p_t->field;
	return (len);
}

int		set_c_inside(unsigned char c, int len, t_printf *p_t)
{
	if (p_t->flag_align_left == 1)
	{
		pad_u_c(0, 1, c, p_t);
		pad_letter(1, len, ' ', p_t);
	}
	else
	{
		if (p_t->flag_zero == 1)
			pad_letter(0, (len - 1), '0', p_t);
		else
			pad_letter(0, (len - 1), ' ', p_t);
		pad_u_c((len - 1), len, c, p_t);
	}
	return (0);
}
