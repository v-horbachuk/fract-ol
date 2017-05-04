/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:51:25 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/15 16:53:16 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wtf(char **line, char *str)
{
	*line = ft_strnew(0);
	if (str)
		free(str);
	return (0);
}

void		ft_fill_line(t_str *array, char **line, const int fd)
{
	size_t		i;

	i = 0;
	while (array[fd].str[i] != '\n' && array[fd].str[i] != '\0')
		i++;
	*line = ft_strsub(array[fd].str, 0, i);
	i++;
	array[fd].str = ft_strsub(array[fd].str, i, (ft_strlen(array[fd].str) - i));
}

int			get_next_line(const int fd, char **line)
{
	int				read_ret;
	char			*buf;
	static t_str	array[OPEN_MAX];

	if (!(buf = ft_strnew(BUFF_SIZE)) || fd > OPEN_MAX || fd < 0)
		return (-1);
	while ((read_ret = read(fd, buf, BUFF_SIZE)))
	{
		if (read_ret < 0)
			return (-1);
		buf[read_ret] = '\0';
		if (!array[fd].str)
			array[fd].str = ft_strnew(0);
		array[fd].str = ft_strjoin(array[fd].str, buf);
		if (ft_strchr(array[fd].str, '\n'))
			break ;
	}
	if (read_ret == 0 && buf[0] == 0 && array[fd].str[0] == 0)
		return (ft_wtf(line, array[fd].str));
	ft_fill_line(array, line, fd);
	return (1);
}
