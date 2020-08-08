/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 07:26:57 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/08 17:26:30 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flag(t_printf *p_t)
{
	while (*(p_t->f_tmp))
	{
		if (*(p_t->f_tmp) == '-')
			p_t->flag_align_left = 1;
		else if (*(p_t->f_tmp) == '0')
			p_t->flag_zero = 1;
		else
			break ;
		p_t->f_tmp++;
	}
	if (p_t->flag_align_left == 1)
		p_t->flag_zero = 0;
	return (0);
}

int		parse_asta(int flag, t_printf *p_t)
{
	int	tmp;

	tmp = va_arg(p_t->ap, int);
	if (tmp >= 0)
	{
		if (flag == 0)
			p_t->field = tmp;
		else
			p_t->precision = tmp;
	}
	else
	{
		if (flag == 0)
			p_t->field = -tmp;
		else
			p_t->precision = -tmp;
		p_t->flag_align_left = 1;
	}
	p_t->f_tmp++;
	return (0);
}

int		parse_field_width(t_printf *p_t)
{

	if (*(p_t->f_tmp) == '*')
		parse_asta(0, p_t);
	else
	{
		if (ft_isdigit(*(p_t->f_tmp)) != 0)
			p_t->field = 0;
		while (ft_isdigit(*(p_t->f_tmp)) != 0)
		{
			p_t->field *= 10;
			p_t->field += *(p_t->f_tmp) - '0';
			p_t->f_tmp++;
			if (p_t->field > INT_MAX || p_t->field < INT_MIN)
				return (-1);
		}
	}
	return (0);
}

int		parse_precision(t_printf *p_t)
{
	if (*(p_t->f_tmp) != '.')
		return (0);
	else
		p_t->precision = 0;
	p_t->f_tmp++;
	if (*(p_t->f_tmp) == '*')
		parse_asta(1, p_t);
	else
	{
		while (ft_isdigit(*(p_t->f_tmp)) != 0)
		{
			p_t->precision *= 10;
			p_t->precision += *(p_t->f_tmp) - '0';
			p_t->f_tmp++;
			if (p_t->precision > INT_MAX || p_t->precision < INT_MIN)
				return (-1);
		}
	}
	return (0);
}

int		parse_conversion(t_printf *p_t)
{
	p_t->conversion = *p_t->f_tmp;
	p_t->f_tmp++;
	return (0);
}
