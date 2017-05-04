/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:15:18 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/01 14:24:15 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	char		*s;

	d = dst;
	s = (void *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
