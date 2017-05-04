/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:57:29 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/01 20:07:11 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t res;

	if (!s1 || !s2)
		return (0);
	res = ft_strcmp(s1, s2);
	if (res == 0)
		return (1);
	return (0);
}
