/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:56:41 by vhorbach          #+#    #+#             */
/*   Updated: 2017/05/12 18:56:45 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_colour(int keycode, t_all *all)
{
	if (keycode == 85)
		ft_change_blue(all, 1);
	else if (keycode == 83)
		ft_change_blue(all, -1);
	else if (keycode == 88)
		ft_change_green(all, 2);
	else if (keycode == 86)
		ft_change_green(all, -2);
	else if (keycode == 92)
		ft_change_red(all, 5);
	else if (keycode == 89)
		ft_change_red(all, -5);
	return (0);
}

int		key_hook(int keycode, t_all *all)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 49)
	{
		all->p.flag = 1;
		ft_std_fract_data(all);
	}
	else if (keycode == 124)
		move_xy(all, 1);
	else if (keycode == 123)
		move_xy(all, -1);
	else if (keycode == 126)
		move_xy(all, -2);
	else if (keycode == 125)
		move_xy(all, 2);
	else if (keycode == 24 || keycode == 69)
		move_xy(all, 4);
	else if (keycode == 27 || keycode == 78)
		move_xy(all, -4);
	else
		key_colour(keycode, all);
	return (0);
}

int		mouse_hook_vary(int x, int y, t_all *all)
{
	if (x > 0 && x < IMG_WID && y > 0 && y < IMG_HIGH && all->fract.mouse == 0)
	{
		if (all->fract.flag == 1 || all->fract.flag == 3)
		{
			all->fract.flag == 1 ? all->fract.cr = -0.7 : 0.41;
			all->fract.flag == 1 ? all->fract.ci = 0.27015 : 0.623454;
			all->fract.flag == 3 ? all->fract.cr = 0.41 : -0.7;
			all->fract.flag == 3 ? all->fract.ci = 0.623454 : 0.27015;
			all->fract.cr += ((double)x - IMG_WID / 2.) / (double)IMG_WID;
			all->fract.ci += ((double)y - IMG_HIGH / 2.) / (double)IMG_HIGH;
		}
		else if (all->fract.flag == 2)
		{
			all->fract.mr = 0;
			all->fract.mi = 0;
			all->fract.mr += ((double)x - IMG_WID / 2) / (double)IMG_WID;
			all->fract.mi += ((double)y - IMG_HIGH / 2) / (double)IMG_HIGH;
		}
	}
	ft_threads(all);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_all *all)
{
	if (button == 4)
	{
		all->fract.zoom = all->fract.zoom + .1;
		all->fract.move_x += (x - IMG_WID / 2) /
				(IMG_WID * all->fract.zoom * 3);
		all->fract.move_y += (y - IMG_HIGH / 2) /
				(IMG_HIGH * all->fract.zoom * 3);
	}
	else if (button == 5)
	{
		all->fract.zoom = all->fract.zoom - .1;
		all->fract.move_x += (x - IMG_WID / 2) /
				(IMG_WID * all->fract.zoom * 3);
		all->fract.move_y += (y - IMG_HIGH / 2) /
				(IMG_HIGH * all->fract.zoom * 3);
	}
	if (all->fract.zoom < 0.09)
		all->fract.zoom = 0.09;
	if (button == 1)
	{
		mlx_hook(all->mlx.win, 6, (1L << 6), mouse_hook_vary, all);
		m_hook(all);
	}
	ft_threads(all);
	return (0);
}
