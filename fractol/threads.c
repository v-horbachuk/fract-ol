/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:58:59 by vhorbach          #+#    #+#             */
/*   Updated: 2017/05/12 18:59:02 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*data_create(t_all *all, t_data *d, int i)
{
	int		lines;

	lines = IMG_HIGH / THREAD + 1;
	d = (t_data *)malloc(sizeof(t_data));
	d->start = i * lines;
	d->end = (i + 1) * lines;
	if (d->end > IMG_HIGH)
		d->end = IMG_HIGH;
	d->a = *all;
	return (d);
}

void	ft_threads(t_all *all)
{
	int				i;
	t_data			*data;
	pthread_t		threads[THREAD];
	pthread_attr_t	attr;

	i = -1;
	data = NULL;
	pthread_attr_init(&attr);
	all->mlx.img = mlx_new_image(all->mlx.mlx, IMG_WID, IMG_HIGH);
	all->mlx.gda = mlx_get_data_addr(all->mlx.img, &all->mlx.bpp,
									 &all->mlx.sl, &all->mlx.endian);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	while (++i < THREAD)
	{
		data = data_create(all, data, i);
		pthread_create(&threads[i], &attr, ft_fractal, (void *)data);
	}
	pthread_attr_destroy(&attr);
	i = 0;
	while (i < THREAD)
		pthread_join(threads[i++], NULL);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}
