/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 07:32:42 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/06 16:53:59 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_s(char *s, t_printf *p_t)
{
	int	len;
	int	s_len;

	s_len = ft_strlen(s);
	len = set_len_s(s_len, p_t);
	if (!(p_t->o_tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	p_t->o_tmp[len] = '\0';
	set_s_inside(s, s_len, len, p_t);
	return (0);
}

int		set_len_s(int s_len, t_printf *p_t)
{
	int	len;

	if (p_t->field == -1 && p_t->precision == -1)
		len = s_len;
	else if (p_t->field == -1 && p_t->precision != -1)
		len = (s_len > p_t->precision ? p_t->precision : s_len);
	else if (p_t->field != -1 && p_t->precision == -1)
		len = p_t->field;
	else
	{
		if (p_t->field > s_len)
			len = p_t->field;
		else
		{
			if (s_len > p_t->precision)
				len = p_t->field;
			else
				len = s_len;
		}
	}
	return (len);
}

int		set_s_inside(char *s, int s_len, int len, t_printf *p_t)
{
	if (p_t->flag_align_left == 1)
	{
		if (p_t->precision < s_len)
			p_t->precision = s_len;
		pad_letter(0, (p_t->precision - s_len), '0', p_t);
		pad_str((p_t->precision - s_len), p_t->precision, s, p_t);
		pad_letter(p_t->precision, len, ' ', p_t);
	}
	else
	{
		if (p_t->flag_zero == 1 && p_t->precision == -1)
			p_t->precision = p_t->field;
		else if (len < s_len)
			s_len = len;
		else if (p_t->precision < s_len)
			p_t->precision = s_len;
		pad_letter(0, (len - p_t->precision), ' ', p_t);
		pad_letter((len - p_t->precision), (len - s_len), '0', p_t);
		pad_str((len - s_len), len, s, p_t);
	}
	return (0);
}
