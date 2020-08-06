/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 08:38:38 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/06 16:24:20 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_d(int d, t_printf *p_t)
{
	char	*str_d;
	int		len;
	int		d_len;

	str_d = ft_itoa(d);
	d_len = ft_strlen(str_d);
	len = set_len_d(d, d_len, p_t);
	if (!(p_t->o_tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	p_t->o_tmp[len] = '\0';
	if (d >= 0)
		set_d_inside_plus(str_d, d_len, len, p_t);
	else
		set_d_inside_minus(str_d, d_len, len, p_t);
	free(str_d);
	return (0);
}

int		set_len_d(int d, int d_len, t_printf *p_t)
{
	int	len;
	int	num_len;

	if (d >= 0)
	{
		if (p_t->precision < d_len)
			num_len = d_len;
		else
			num_len = p_t->precision;
	}
	else
	{
		if (p_t->precision < d_len)
			num_len = d_len + 1;
		else
			num_len = p_t->precision + 1;
	}
	if (num_len > p_t->field)
		len = num_len;
	else
		len = p_t->field;
	return (len);
}

int		set_d_inside_plus(char *str_d, int d_len, int len, t_printf *p_t)
{
	if (p_t->flag_align_left == 1)
	{
		if (p_t->precision < d_len)
			p_t->precision = d_len;
		pad_letter(0, (p_t->precision - d_len), '0', p_t);
		pad_str((p_t->precision - d_len), p_t->precision, str_d, p_t);
		pad_letter(p_t->precision, len, ' ', p_t);
	}
	else
	{
		if (p_t->flag_zero == 1 && p_t->precision == -1)
			p_t->precision = p_t->field;
		else if (p_t->precision < d_len)
			p_t->precision = d_len;
		pad_letter(0, (len - p_t->precision), ' ', p_t);
		pad_letter((len - p_t->precision), (len - d_len), '0', p_t);
		pad_str((len - d_len), len, str_d, p_t);
	}
	return (0);
}

int		set_d_inside_minus(char *str_d, int d_len, int len, t_printf *p_t)
{
	str_d++;
	d_len--;
	if (p_t->flag_align_left == 1)
	{
		if (p_t->precision < d_len)
			p_t->precision = d_len;
		pad_letter(0, 1, '-', p_t);
		pad_letter(1, (len - p_t->precision - 1 - d_len), '0', p_t);
		pad_str((len - p_t->precision - 1 - d_len), (len - p_t->precision - 1), str_d, p_t);
		pad_letter((len - p_t->precision - 1), len, ' ', p_t);
	}
	else
	{
		if (p_t->flag_zero == 1 && p_t->precision == -1)
			p_t->precision = p_t->field;
		else if (p_t->precision < d_len)
			p_t->precision = d_len;
		pad_letter(0, (len - p_t->precision - 1), ' ', p_t);
		pad_letter((len - p_t->precision - 1), (len - p_t->precision),
					'-', p_t);
		pad_letter((len - p_t->precision), (len - d_len), '0', p_t);
		pad_str((len - d_len), len, str_d, p_t);
	}
	return (0);
}
