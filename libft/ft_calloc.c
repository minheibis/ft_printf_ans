/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:27:36 by hyuki             #+#    #+#             */
/*   Updated: 2020/06/27 22:36:02 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	size_t	nbytes;

	nbytes = nmemb * size;
	if (!(dest = (void *)malloc(nbytes)))
		return (NULL);
	ft_bzero(dest, nbytes);
	return (dest);
}
