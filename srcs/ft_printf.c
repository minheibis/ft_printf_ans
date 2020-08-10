/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 07:26:41 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/10 20:45:18 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	t;

	init_t_printf(&t);
	va_start(t.ap, format);
	if (!(t.format = ft_strdup(format)))
		return (-1);
	t.f_tmp = t.format;
	if (!(t.output = ft_strdup("")))
		return (-1);
	if (read_format(&t) == -1)
		return (free_t_printf(&t, -1));
	write(1, t.output, t.rv);
	va_end(t.ap);
	return (free_t_printf(&t, t.rv));
}

int		read_format(t_printf *p_t)
{
	while (*(p_t->f_tmp) != '\0')
	{
		p_t->rv_tmp = 0;
		while ((p_t->f_tmp)[p_t->rv_tmp] != '%'
				&& (p_t->f_tmp)[p_t->rv_tmp] != '\0')
			p_t->rv_tmp++;
		if (!(p_t->o_tmp = ft_substr(p_t->f_tmp, 0, p_t->rv_tmp)))
			return (-1);
		if (!(p_t->output = free_join_output(p_t)))
			return (-1);
		if ((p_t->f_tmp)[p_t->rv_tmp] == '\0')
			break ;
		p_t->f_tmp += (p_t->rv_tmp + 1);
		p_t->rv_tmp = 0;
		init_flags(p_t);
		if (parse_format(p_t) == -1)
			return (-1);
		if (set_tmp(p_t) == -1)
			return (-1);
		if (!(p_t->output = free_join_output(p_t)))
			return (-1);
	}
	return (0);
}

int		parse_format(t_printf *p_t)
{
	if (parse_flag(p_t) == -1)
		return (-1);
	if (parse_field_width(p_t) == -1)
		return (-1);
	if (parse_precision(p_t) == -1)
		return (-1);
	if (parse_conversion(p_t) == -1)
		return (-1);
	return (0);
}

int		set_tmp(t_printf *p_t)
{
	if (p_t->conversion == 'c')
		return ((unsigned char)set_c(va_arg(p_t->ap, int), p_t));
	else if (p_t->conversion == 's')
		return (set_s(va_arg(p_t->ap, char *), p_t));
	else if (p_t->conversion == 'p')
		return (set_p(va_arg(p_t->ap, void *), p_t));
	else if (p_t->conversion == 'd' || p_t->conversion == 'i')
		return (set_d(va_arg(p_t->ap, int), p_t));
	else if (p_t->conversion == 'u')
		return (set_u(va_arg(p_t->ap, unsigned int), 'u', p_t));
	else if (p_t->conversion == 'x')
		return (set_u(va_arg(p_t->ap, unsigned int), 'x', p_t));
	else if (p_t->conversion == 'X')
		return (set_u(va_arg(p_t->ap, unsigned int), 'X', p_t));
	else if (p_t->conversion == '%')
		return (set_per(p_t));
	else
		return (-1);
}
