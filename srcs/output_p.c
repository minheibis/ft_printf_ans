/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 07:43:57 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/10 20:53:31 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_p(void *p, t_printf *p_t)
{
	char	*str_p;
	int		len;
	int		p_len;

	if (p == NULL && p_t->precision == 0)
	{
		if (!(str_p = ft_strdup("")))
			return (-1);
	}
	else
	{
		if (!(str_p = utoa_base_low((long)p, 16)))
			return (-1);
	}
	p_len = ft_strlen(str_p);
	len = set_len_p(p_len, p_t);
	if (!(p_t->o_tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	p_t->o_tmp[len] = '\0';
	set_p_inside(str_p, p_len, len, p_t);
	free(str_p);
	p_t->rv_tmp = len;
	return (0);
}

int		set_len_p(int p_len, t_printf *p_t)
{
	int	len;

	len = p_t->field;
	if (p_t->precision == -1)
	{
		if ((p_len + 2) > p_t->field)
			len = p_len + 2;
	}
	else
	{
		if (p_len > p_t->precision && ((p_len + 2) > p_t->field))
			len = (p_len + 2);
		else if ((p_t->precision + 2) > p_t->field)
			len = (p_t->precision + 2);
	}
	return (len);
}

int		set_p_inside(char *str_p, int p_len, int len, t_printf *p_t)
{
	if (p_t->flag_align_left == 1)
	{
		if (p_t->precision < p_len)
			p_t->precision = p_len;
		pad_str(0, 2, "0x", p_t);
		pad_letter(2, (p_t->precision - p_len + 2), '0', p_t);
		pad_str((p_t->precision - p_len + 2), (p_t->precision + 2), str_p, p_t);
		pad_letter((p_t->precision + 2), len, ' ', p_t);
	}
	else
	{
		if (p_t->flag_zero == 1 && p_t->precision == -1)
			p_t->precision = (p_t->field - 2);
		else if (p_t->precision < p_len)
			p_t->precision = p_len;
		pad_letter(0, (len - p_t->precision - 2), ' ', p_t);
		pad_str((len - p_t->precision - 2), (len - p_t->precision), "0x", p_t);
		pad_letter((len - p_t->precision), (len - p_len), '0', p_t);
		pad_str((len - p_len), len, str_p, p_t);
	}
	return (0);
}
