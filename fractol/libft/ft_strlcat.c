/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:20:28 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/08 18:20:38 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t d;
	size_t s;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (size > d)
	{
		while (src[i] && d < size - 1)
		{
			dst[d] = src[i];
			i++;
			d++;
		}
		dst[d] = '\0';
		return ((s - i) + d);
	}
	return (s + size);
}
