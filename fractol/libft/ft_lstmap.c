/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:00:57 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/08 17:35:57 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstres;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	lstres = (t_list*)malloc(sizeof(t_list));
	if (!lstres)
		return (0);
	lstres = f(lst);
	temp = lstres;
	lst = lst->next;
	while (lst != NULL)
	{
		temp->next = (t_list*)malloc(sizeof(t_list));
		if (!lstres->next)
			return (0);
		temp->next = f(lst);
		temp = temp->next;
		lst = lst->next;
	}
	return (lstres);
}
