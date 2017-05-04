/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:35:32 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/01 15:08:04 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;
	char	*s1;

	i = 0;
	tmp = 0;
	s1 = (char *)s;
	while (s1[i])
	{
		if (s1[i] == c)
			tmp = &s1[i];
		i++;
	}
	if (s1[i] == '\0' && c == '\0')
		return (&s1[i]);
	return (tmp);
}
