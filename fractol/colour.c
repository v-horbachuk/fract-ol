/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:47:58 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/08 17:48:03 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	changed_fract(t_all *all)
{
	if (all->fract.flag == 1)
		ft_julia_1(all);
	else if (all->fract.flag == 3)
		ft_julia3_1(all);
	else if (all->fract.flag == 2)
		ft_mandelbrot_1(all);
}

void	ft_change_blue(t_all *all, double param)
{
	if (param == 1 || param == -1)
	{
		param *= 10;
		if (all->p.start_c_b >= 255 && all->p.end_c_b >= 255)
		{
			all->p.start_c_b -= param;
			all->p.end_c_b -= param;
		}
		else if (all->p.start_c_b <= 0 && all->p.end_c_b <= 0)
		{
			all->p.start_c_b -= param;
			all->p.end_c_b -= param;
		}
		else
		{
			all->p.start_c_b += param;
			all->p.end_c_b += param;
		}
		changed_fract(all);
	}
}

void	ft_change_green(t_all *all, double param)
{
	if (param == 2 || param == -2)
	{
		param *= 5;
		if (all->p.start_c_g >= 255 && all->p.end_c_g >= 255)
		{
			all->p.start_c_g -= param;
			all->p.end_c_g -= param;
		}
		else if (all->p.start_c_g <= 0 && all->p.end_c_g <= 0)
		{
			all->p.start_c_g -= param;
			all->p.end_c_g -= param;
		}
		else
		{
			all->p.start_c_g += param;
			all->p.end_c_g += param;
		}
		changed_fract(all);
	}
}

void	ft_change_red(t_all *all, double param)
{
	if (param == 5 || param == -5)
	{
		param *= 2;
		if (all->p.start_c_r >= 255 && all->p.end_c_r >= 255)
		{
			all->p.start_c_r -= param;
			all->p.end_c_r -= param;
		}
		else if (all->p.start_c_r <= 0 && all->p.end_c_r <= 0)
		{
			all->p.start_c_r -= param;
			all->p.end_c_r -= param;
		}
		else
		{
			all->p.start_c_r += param;
			all->p.end_c_r += param;
		}
		changed_fract(all);
	}
}

void	ft_std_fract_data(t_all *all)
{
	all->p.end_c_b = 123;
	all->p.end_c_g = 212;
	all->p.end_c_r = 22;
	all->p.start_c_b = 132;
	all->p.start_c_g = 22;
	all->p.start_c_r = 92;
	if (all->fract.flag == 1 || all->fract.flag == 3)
	{
		all->fract.zoom = 1;
		all->fract.move_x = 0;
		all->fract.move_y = 0;
		all->fract.cr = -0.7;
		all->fract.ci = 0.27015;
		if (all->p.flag == 1)
			changed_fract(all);
	}
	else if (all->fract.flag == 2)
	{
		all->fract.zoom = 1;
		all->fract.move_x = -0.5;
		all->fract.move_y = 0;
		if (all->p.flag == 1)
			changed_fract(all);
	}
}
