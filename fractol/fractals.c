/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:30:50 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/24 21:16:48 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_mandelbrot(t_data *d)
{
	while (d->a.fract.i < ITER)
	{
		d->a.fract.or = d->a.fract.nr;
		d->a.fract.oi = d->a.fract.ni;
		d->a.fract.nr = d->a.fract.or * d->a.fract.or -
						d->a.fract.oi * d->a.fract.oi + d->a.fract.pr;
		d->a.fract.ni = 2 * d->a.fract.or * d->a.fract.oi + d->a.fract.pi;
		if ((d->a.fract.nr * d->a.fract.nr + d->a.fract.ni * d->a.fract.ni) > 4)
			break ;
		d->a.fract.i++;
	}
	return (d->a.fract.i);
}

int			ft_julia(t_data *d)
{
	while (d->a.fract.i < ITER)
	{
		d->a.fract.or = d->a.fract.nr;
		d->a.fract.oi = d->a.fract.ni;
		d->a.fract.nr = d->a.fract.or * d->a.fract.or -
						d->a.fract.oi * d->a.fract.oi + d->a.fract.cr;
		d->a.fract.ni = 2 * d->a.fract.or * d->a.fract.oi + d->a.fract.ci;
		if ((d->a.fract.nr * d->a.fract.nr + d->a.fract.ni * d->a.fract.ni) > 4)
			break ;
		d->a.fract.i++;
	}
	return (d->a.fract.i);
}

int			ft_julia_3(t_data *d)
{
	while (d->a.fract.i < ITER)
	{
		d->a.fract.or = d->a.fract.nr;
		d->a.fract.oi = d->a.fract.ni;
		d->a.fract.nr = d->a.fract.or * d->a.fract.or * d->a.fract.or -
				3 * d->a.fract.or * d->a.fract.oi *
						d->a.fract.oi + d->a.fract.cr;
		d->a.fract.ni = 3 * d->a.fract.or * d->a.fract.or * d->a.fract.oi -
				d->a.fract.oi * d->a.fract.oi * d->a.fract.oi + d->a.fract.ci;
		if ((d->a.fract.nr * d->a.fract.nr + d->a.fract.ni * d->a.fract.ni) > 4)
			break ;
		d->a.fract.i++;
	}
	return (d->a.fract.i);
}

void		ft_one_more_time(t_data *d)
{
	if (d->a.fract.flag == 1 || d->a.fract.flag == 3)
	{
		d->a.fract.nr = 1.5 * (d->a.fract.x - IMG_WID / 2) /
						(0.5 * d->a.fract.zoom * IMG_WID) + d->a.fract.move_x;
		d->a.fract.ni = (d->a.fract.y - IMG_HIGH / 2) /
						(0.5 * d->a.fract.zoom * IMG_HIGH) + d->a.fract.move_y;
	}
	else if (d->a.fract.flag == 2)
	{
		d->a.fract.nr = d->a.fract.mr;
		d->a.fract.ni = d->a.fract.mi;
		d->a.fract.pr = 1.5 * (d->a.fract.x - IMG_WID / 2) / (0.5 *
				d->a.fract.zoom * IMG_WID) + d->a.fract.move_x;
		d->a.fract.pi = (d->a.fract.y - IMG_HIGH / 2) / (0.5 *
				d->a.fract.zoom * IMG_HIGH) + d->a.fract.move_y;
	}
}

void		*ft_fractal(void *data)
{
	t_data *d;

	d = (t_data *)data;
	d->a.fract.y = d->start - 1;
	while (++d->a.fract.y < d->end)
	{
		d->a.fract.x = -1;
		while (++d->a.fract.x < IMG_WID)
		{
			ft_one_more_time(d);
			d->a.fract.i = 0;
			if (d->a.fract.flag == 1)
				d->a.fract.i = ft_julia(d);
			else if (d->a.fract.flag == 2)
				d->a.fract.i = ft_mandelbrot(d);
			else if (d->a.fract.flag == 3)
				d->a.fract.i = ft_julia_3(d);
			draw_pixel(d->a.fract.x, d->a.fract.y, d);
		}
	}
	pthread_exit(d);
}
