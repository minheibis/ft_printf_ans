/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 23:34:20 by hyuki             #+#    #+#             */
/*   Updated: 2020/07/02 17:42:13 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp_list;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp_list = (*lst)->next;
		if (del != NULL)
			del((*lst)->content);
		free(*lst);
		*lst = tmp_list;
	}
}
