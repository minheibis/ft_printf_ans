/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:50:03 by hyuki             #+#    #+#             */
/*   Updated: 2020/07/02 18:53:39 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int ans;

	if (lst == NULL)
		return (0);
	ans = 1;
	while (lst->next != NULL)
	{
		ans++;
		lst = lst->next;
	}
	return (ans);
}
