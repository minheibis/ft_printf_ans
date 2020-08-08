/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_toa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:56:49 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/08 16:18:41 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		a_base_len(unsigned int num, int base)
{
	int	len;

	len = 1;
	while (num > (base - 1))
	{
		num /= base;
		len++;
	}
	return (len);
}

char	*utoa_base_low(unsigned int num, int base)
{
	char	*base_char;
	char	*ans;
	int		len;

	base_char = "0123456789abcdef";
	len = a_base_len(num, base);
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ans[len] = '\0';
	while (len-- > 0)
	{
		ans[len] = base_char[num % base];
		num /= base;
	}
	return (ans);
}

char	*utoa_base_up(unsigned int num, int base)
{
	char	*base_char;
	char	*ans;
	int		len;

	base_char = "0123456789ABCDEF";
	len = a_base_len(num, base);
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ans[len] = '\0';
	while (len-- > 0)
	{
		ans[len] = base_char[num % base];
		num /= base;
	}
	return (ans);
}
