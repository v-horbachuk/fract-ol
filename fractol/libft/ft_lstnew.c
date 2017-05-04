/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:58:02 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/08 12:17:21 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content_size = content_size;
		lst->content = ft_memalloc(lst->content_size);
		if (!lst->content)
			return (NULL);
		lst->content = ft_memcpy(lst->content, content, lst->content_size);
	}
	lst->next = NULL;
	return (lst);
}
