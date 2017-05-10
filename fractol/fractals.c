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
	changed_fract(all);
}

void		draw_pixel(int x, int y, t_all *all)
{
	int		a;

	all->p.final_c_b = (all->p.end_c_b - all->p.start_c_b) *
					(all->p.start_c_b + all->fract.i / ITER);
	all->p.final_c_g = (all->p.end_c_g - all->p.start_c_g) *
					(all->p.start_c_g + all->fract.i / ITER);
	all->p.final_c_r = (all->p.end_c_r - all->p.start_c_r) *
					(all->p.start_c_r + all->fract.i / ITER);
	all->p.opacity = 0;
	a = (4 * (y * IMG_WID + x));
	if (x < 0 || x >= WIN_WID || y < 0 || y >= WIN_HIGH)
		return ;
	all->mlx.gda[a] = (char)all->p.final_c_b;
	all->mlx.gda[a + 1] = (char)all->p.final_c_g;
	all->mlx.gda[a + 2] = (char)all->p.final_c_r;
	all->mlx.gda[a + 3] = (char)all->p.opacity;
}

int			ft_julia_2(t_all *all)
{
	while (all->fract.i < ITER)
	{
		all->fract.or = all->fract.nr;
		all->fract.oi = all->fract.ni;
		all->fract.nr = all->fract.or * all->fract.or -
						all->fract.oi * all->fract.oi + all->fract.cr;
		all->fract.ni = 2 * all->fract.or * all->fract.oi + all->fract.ci;
		if ((all->fract.nr * all->fract.nr + all->fract.ni * all->fract.ni) > 4)
			break ;
		all->fract.i++;
	}
	return (all->fract.i);
}

void		ft_julia_1(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx, IMG_WID, IMG_HIGH);
	all->mlx.gda = mlx_get_data_addr(all->mlx.img, &all->mlx.bpp,
								&all->mlx.sl, &all->mlx.endian);
	all->fract.y = -1;
	while (++all->fract.y < IMG_HIGH)
	{
		all->fract.x = -1;
		while (++all->fract.x < IMG_WID)
		{
			all->fract.nr = 1.5 * (all->fract.x - IMG_WID / 2) /
						(0.5 * all->fract.zoom * IMG_WID) + all->fract.move_x;
			all->fract.ni = (all->fract.y - IMG_HIGH / 2) /
						(0.5 * all->fract.zoom * IMG_HIGH) + all->fract.move_y;
			all->fract.i = 0;
			all->fract.i = ft_julia_2(all);
			draw_pixel(all->fract.x, all->fract.y, all);
		}
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}

int			ft_mandelbrot_2(t_all *all)
{
	while (all->fract.i < ITER)
	{
		all->fract.or = all->fract.nr;
		all->fract.oi = all->fract.ni;
		all->fract.nr = all->fract.or * all->fract.or -
				all->fract.oi * all->fract.oi + all->fract.pr;
		all->fract.ni = 2 * all->fract.or * all->fract.oi + all->fract.pi;
		if ((all->fract.nr * all->fract.nr + all->fract.ni * all->fract.ni) > 4)
			break ;
		all->fract.i++;
	}
	return (all->fract.i);
}

void		ft_mandelbrot_1(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx, IMG_WID, IMG_HIGH);
	all->mlx.gda = mlx_get_data_addr(all->mlx.img, &all->mlx.bpp,
									&all->mlx.sl, &all->mlx.endian);
	all->fract.y = -1;
	while (++all->fract.y < IMG_HIGH)
	{
		all->fract.x = -1;
		while (++all->fract.x < IMG_WID)
		{
			all->fract.nr = 0;
			all->fract.ni = 0;
			all->fract.pr = 1.5 * (all->fract.x - IMG_WID / 2) / (0.5 *
					all->fract.zoom * IMG_WID) + all->fract.move_x;
			all->fract.pi = (all->fract.y - IMG_HIGH / 2) / (0.5 *
					all->fract.zoom * IMG_HIGH) + all->fract.move_y;
			all->fract.i = 0;
			all->fract.i = ft_mandelbrot_2(all);
			draw_pixel(all->fract.x, all->fract.y, all);
		}
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}
