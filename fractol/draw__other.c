/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_&_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:54:28 by vhorbach          #+#    #+#             */
/*   Updated: 2017/05/12 19:16:21 by vhorbach         ###   ########.fr       */
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
		d->a.fract.i / ITER + d->a.p.start_c_b;
	d->a.p.final_c_g = (d->a.p.end_c_g - d->a.p.start_c_g) *
		d->a.fract.i / ITER + d->a.p.start_c_g;
	d->a.p.final_c_r = (d->a.p.end_c_r - d->a.p.start_c_r) *
		d->a.fract.i / ITER + d->a.p.start_c_r;
	d->a.p.opacity = 0;
	a = (4 * (y * IMG_WID + x));
	if (x < 0 || x >= WIN_WID || y < 0 || y >= WIN_HIGH)
		return ;
	d->a.mlx.gda[a] = (char)d->a.p.final_c_b;
	d->a.mlx.gda[a + 1] = (char)d->a.p.final_c_g;
	d->a.mlx.gda[a + 2] = (char)d->a.p.final_c_r;
	d->a.mlx.gda[a + 3] = (char)d->a.p.opacity;
}

void		ft_std_data_2(t_all *all)
{
	all->fract.zoom = 0.85;
	all->fract.move_x = 0;
	all->fract.move_y = 0.135;
	all->fract.cr = 0.41;
	all->fract.ci = 0.623454;
	if (all->p.flag == 1)
		ft_threads(all);
}

void		ft_std_data_1(t_all *all)
{
	all->fract.mr = 0;
	all->fract.mi = 0;
	all->fract.zoom = 1;
	all->fract.move_x = -0.5;
	if (all->p.flag == 1)
		ft_threads(all);
}

void		m_hook(t_all *all)
{
	if (all->fract.mouse == 1)
		all->fract.mouse = 0;
	else
		all->fract.mouse = 1;
}
