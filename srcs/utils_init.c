/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:13:11 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/06 16:50:54 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_t_printf(t_printf *p_t)
{
	p_t->format = NULL;
	p_t->f_tmp = NULL;
	p_t->output = NULL;
	p_t->o_tmp = NULL;
	p_t->rv = 0;
	p_t->flag_align_left = 0;
	p_t->flag_zero = 0;
	p_t->field = -1;
	p_t->precision = -1;
	p_t->conversion = '\0';
}

void	init_flags(t_printf *p_t)
{
	p_t->flag_align_left = 0;
	p_t->flag_zero = 0;
	p_t->field = -1;
	p_t->precision = -1;
	p_t->conversion = '\0';
}
