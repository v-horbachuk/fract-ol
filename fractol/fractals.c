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

void		move_xy(t_all *all, double param)
{
	if (param == 1 || param == -1)
		all->fract.move_x = all->fract.move_x - param / 4;
	else if (param == 2 || param == -2)
		all->fract.move_y = all->fract.move_y - param / 8;
	else if (param == 4 || param == -4)
		all->fract.zoom = all->fract.zoom + param / 20;
	ft_threads(all);
}

void		draw_pixel(int x, int y, t_data *d)
{
	int		a;

	d->a.p.final_c_b = (d->a.p.end_c_b - d->a.p.start_c_b) *
					   (d->a.p.start_c_b + d->a.fract.i / ITER);
	d->a.p.final_c_g = (d->a.p.end_c_g - d->a.p.start_c_g) *
					   (d->a.p.start_c_g + d->a.fract.i / ITER);
	d->a.p.final_c_r = (d->a.p.end_c_r - d->a.p.start_c_r) *
					   (d->a.p.start_c_r + d->a.fract.i / ITER);
	d->a.p.opacity = 0;
	a = (4 * (y * IMG_WID + x));
	if (x < 0 || x >= WIN_WID || y < 0 || y >= WIN_HIGH)
		return ;
	d->a.mlx.gda[a] = (char)d->a.p.final_c_b;
	d->a.mlx.gda[a + 1] = (char)d->a.p.final_c_g;
	d->a.mlx.gda[a + 2] = (char)d->a.p.final_c_r;
	d->a.mlx.gda[a + 3] = (char)d->a.p.opacity;
}

int			ft_mandelbrot_2(t_data *d)
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

int			ft_julia_2(t_data *d)
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

int			ft_julia3_2(t_data *d)
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
		d->a.fract.nr = 0;
		d->a.fract.ni = 0;
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
				d->a.fract.i = ft_julia_2(d);
			else if (d->a.fract.flag == 2)
				d->a.fract.i = ft_mandelbrot_2(d);
			else if (d->a.fract.flag == 1)
				d->a.fract.i = ft_julia3_2(d);
			draw_pixel(d->a.fract.x, d->a.fract.y, d);
		}
	}
	pthread_exit(d);
}
