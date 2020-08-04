/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuki <hyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:59:11 by hyuki             #+#    #+#             */
/*   Updated: 2020/07/02 18:54:17 by hyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*ans_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(new_list = ft_lstnew(f(lst->content))))
		return (NULL);
	ans_list = new_list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(new_list->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&ans_list, del);
			return (NULL);
		}
		new_list = new_list->next;
	}
	return (ans_list);
}
