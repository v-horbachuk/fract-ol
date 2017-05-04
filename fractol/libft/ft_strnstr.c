/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:05:16 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/01 14:55:40 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;
	size_t length;

	i = 0;
	j = 0;
	length = ft_strlen(s2);
	if (length == 0)
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		while (s2[j] == s1[j + i] && (j + i) < len)
		{
			if (j == length - 1)
				return ((char *)s1 + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
