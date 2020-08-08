/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 11:56:20 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/08 09:24:06 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_u(unsigned int u, char cs, t_printf *p_t)
{
	char	*str_u;
	int		len;
	int		u_len;

	if (set_str_u(u, cs, &str_u, p_t) == -1)
		return (-1);
	u_len = ft_strlen(str_u);
	len = set_len_u(u_len, p_t);
	if (!(p_t->o_tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	p_t->o_tmp[len] = '\0';
	set_u_inside(str_u, u_len, len, p_t);
	free(str_u);
	return (0);
}

int		set_str_u(unsigned int u, char cs, char **str_u, t_printf *p_t)
{
	if (u == 0 && p_t->precision == 0)
		*str_u = ft_strdup(" ");
	else if (cs == 'u')
	{
		if (!(*str_u = utoa_base_low(u, 10)))
			return (-1);
	}
	else if (cs == 'x')
	{
		if (!(*str_u = utoa_base_low(u, 16)))
			return (-1);
	}
	else
	{
		if (!(*str_u = utoa_base_up(u, 16)))
			return (-1);
	}
	return (0);
}

int		set_len_u(int u_len, t_printf *p_t)
{
	int	len;
	int	num_len;

	if (p_t->precision < u_len)
		num_len = u_len;
	else
		num_len = p_t->precision;
	len = (num_len > p_t->field ? num_len : p_t->field);
	return (len);
}

int		set_u_inside(char *str_u, int u_len, int len, t_printf *p_t)
{
	if (p_t->flag_align_left == 1)
	{
		if (p_t->precision < u_len)
			p_t->precision = u_len;
		pad_letter(0, (p_t->precision - u_len), '0', p_t);
		pad_str((p_t->precision - u_len), p_t->precision, str_u, p_t);
		pad_letter(p_t->precision, len, ' ', p_t);
	}
	else
	{
		if (p_t->flag_zero == 1 && p_t->precision == -1)
			p_t->precision = p_t->field;
		else if (p_t->precision < u_len)
			p_t->precision = u_len;
		pad_letter(0, (len - p_t->precision), ' ', p_t);
		pad_letter((len - p_t->precision), (len - u_len), '0', p_t);
		pad_str((len - u_len), len, str_u, p_t);
	}
	return (0);
}
