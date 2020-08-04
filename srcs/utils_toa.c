/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_toa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:56:49 by hyuki             #+#    #+#             */
/*   Updated: 2020/08/03 21:56:53 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		a_base_len(int num, int base)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

char	*utoa_base(size_t num, int base)
{
	char	*base_char;
	char	*ans;
	int		len;

	base_char = "0123456789abcdef";
	len = a_base_len(num, base);
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
	ans[len] = '\0';
	while (len-- >= 0)
	{
		ans[len] = base_char[num % base];
		num /= base;
	}
	return (ans);
}

char	*str_toupper(char *str)
{
	while (*str != '\0')
	{
		*str = ft_toupper(*str);
		str++;
	}
	return (str);
}
