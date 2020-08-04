/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 19:23:06 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/27 22:03:57 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ans;
	int		n_copy;
	int		len;

	n_copy = n;
	len = ((n_copy >= 0) ? 1 : 2);
	while (n_copy > 9 || n_copy < -9)
	{
		n_copy = n_copy / 10;
		len++;
	}
	if (!(ans = (char *)malloc(len + 1)))
		return (NULL);
	ans[len--] = '\0';
	if (n == 0)
		ans[0] = '0';
	if (n < 0)
		ans[0] = '-';
	while (n != 0)
	{
		ans[len--] = ((n >= 0) ? ('0' + n % 10) : ('0' - n % 10));
		n = n / 10;
	}
	return (ans);
}
