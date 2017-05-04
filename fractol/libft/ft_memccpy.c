/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:27:27 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/01 14:26:08 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	char		*s;

	d = dst;
	s = (void *)src;
	i = 0;
	while (i < n)
	{
		if ((d[i] = s[i]) == c)
			return (&d[i + 1]);
		i++;
	}
	return (0);
}
