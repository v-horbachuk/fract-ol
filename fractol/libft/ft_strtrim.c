/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:30:03 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/06 16:41:21 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		l;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	l = ft_strlen(s);
	while ((s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t') && l)
		l--;
	str = (char *)malloc(sizeof(*str) * l + 1);
	if (!str)
		return (0);
	while (i < l)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
