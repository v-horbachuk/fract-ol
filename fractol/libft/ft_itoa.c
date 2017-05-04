/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:36:23 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/13 19:15:02 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int		count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		count;
	int		temp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	count = ft_count(n);
	temp = n;
	if (temp < 0)
		temp = -temp;
	if (!(s = ft_memalloc(count + 1)))
		return (0);
	s[count] = '\0';
	while (temp > 0)
	{
		s[--count] = temp % 10 + '0';
		temp = temp / 10;
	}
	if (n < 0)
		s[--count] = '-';
	return (s);
}
