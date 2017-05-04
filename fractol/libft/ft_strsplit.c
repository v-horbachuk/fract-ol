/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:08:04 by vhorbach          #+#    #+#             */
/*   Updated: 2016/12/08 18:24:45 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = -1;
	if (!s)
		return (0);
	str = (char **)malloc(sizeof(char *) * ft_count_words(s, c) + 1);
	if (!str)
		return (0);
	while (++j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		str[j] = ft_strsub(s, start, (i - start));
		i++;
	}
	str[j] = 0;
	return (str);
}
