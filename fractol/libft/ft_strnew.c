/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:33:41 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/01 20:26:41 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (0);
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
