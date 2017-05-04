/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:00:44 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/06 16:41:57 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	j;

	str = (void *)s;
	j = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == j)
			return (&str[i]);
		i++;
	}
	return (0);
}
