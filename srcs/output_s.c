/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 07:32:42 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/11 21:19:40 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_s(char *s, t_printf *p_t)
{
	int		len;
	int		s_len;
	char	c;

	if (s == NULL)
	{
		s = &c;
		if (!(s = ft_strdup("(null)")))
			return (-1);
	}
	s_len = ft_strlen(s);
	len = set_len_s(s_len, p_t);
	if (!(p_t->o_tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	p_t->o_tmp[len] = '\0';
	set_s_inside(s, s_len, len, p_t);
	p_t->rv_tmp = len;
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
		len = (s_len > p_t->field ? s_len : p_t->field);
	else
	{
		if (p_t->field > s_len)
			len = p_t->field;
		else
		{
			if (p_t->precision > p_t->field)
				len = p_t->precision;
			else
				len = p_t->field;
		}
	}
	return (len);
}

int		set_s_inside(char *s, int s_len, int len, t_printf *p_t)
{
	if (p_t->flag_align_left == 1)
	{
		if (p_t->precision == -1 || p_t->precision > s_len)
			p_t->precision = s_len;
		else if (p_t->precision > len)
			p_t->precision = len;
		pad_str(0, p_t->precision, s, p_t);
		if (p_t->flag_zero == 1)
			pad_letter(p_t->precision, len, '0', p_t);
		else
			pad_letter(p_t->precision, len, ' ', p_t);
	}
	else
	{
		if (p_t->precision == -1 || p_t->precision > s_len)
			p_t->precision = s_len;
		else if (p_t->precision > len)
			p_t->precision = len;
		if (p_t->flag_zero == 1)
			pad_letter(0, (len - p_t->precision), '0', p_t);
		else
			pad_letter(0, (len - p_t->precision), ' ', p_t);
		pad_str((len - p_t->precision), len, s, p_t);
	}
	return (0);
}
