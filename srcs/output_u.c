/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 11:56:20 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/06 22:10:34 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_u(unsigned int u, char cs, t_printf *p_t)
{
	char	*str_u;
	int		len;
	int		u_len;

	if (u == 0)
	{
		p_t->o_tmp = ft_strdup("");
		return (0);
	}
	if (set_str_u(u, cs, &str_u) == -1)
		return (-1);
	u_len = ft_strlen(str_u);
	len = ((u_len > p_t->field) ? u_len : p_t->field);
	if (!(p_t->o_tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	p_t->o_tmp[len] = '\0';
	set_u_inside(str_u, u_len, len, p_t);
	free(str_u);
	return (0);
}

int		set_str_u(unsigned int u, char cs, char **str_u)
{
	if (cs == 'u')
	{
		if (!(*str_u = utoa_base(u, 10)))
			return (-1);
	}
	else
	{
		if (!(*str_u = utoa_base(u, 16)))
			return (-1);
		if (cs == 'X')
			*str_u = str_toupper(*str_u);
	}
	return (0);
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
