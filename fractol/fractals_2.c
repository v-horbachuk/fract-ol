/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 20:57:55 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/24 21:08:42 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_julia3_2(t_all *all)
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

void		ft_julia3_1(t_all *all)
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
			all->fract.i = ft_julia3_2(all);
			draw_pixel(all->fract.x, all->fract.y, all);
		}
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}
