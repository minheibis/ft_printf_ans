/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 14:55:44 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/29 16:58:51 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
	c == '\v' || c == '\f' || c == '\r');
}

int			ft_atoi(const char *str)
{
	int nb;
	int pm;

	nb = 0;
	pm = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pm = -pm;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + (int)(*str - '0');
		str++;
	}
	return (pm * nb);
}
