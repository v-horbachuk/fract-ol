/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:19:03 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/01 20:07:03 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	res;

	i = 0;
	if (!s1 || !s2)
		return (0);
	res = ft_strncmp(s1, s2, n);
	if (res == 0)
		return (1);
	return (0);
}
