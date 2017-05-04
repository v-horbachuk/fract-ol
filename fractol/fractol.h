/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:28:06 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/19 11:28:08 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIN_WID 1200
# define WIN_HIGH 900
# define IMG_WID 1200
# define IMG_HIGH 900
# define ITER 300

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <math.h>
# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*gda;
	int				bpp;
	int				sl;
	int				endian;
}					t_mlx;

typedef	struct		s_colour
{
	int				start_c_b;
	int				start_c_g;
	int				start_c_r;
	int				end_c_b;
	int				end_c_g;
	int				end_c_r;
	int				final_c_b;
	int				final_c_g;
	int				final_c_r;
	int				opacity;
	int 			flag;
}					t_colour;

typedef struct		s_fract
{
	double 			cr;
	double			ci;
	double			pr;
	double			pi;
	double			nr;
	double			ni;
	double			or;
	double			oi;
	double			zoom;
	double			move_x;
	double			move_y;
	int				x;
	int				y;
	int				i;
	char 			*string;
	int 			flag;
}					t_fract;

typedef struct		s_all
{
	t_mlx			mlx;
	t_colour		p;
	t_fract			fract;
}					t_all;

void				ft_julia_1(t_all *all);
int 				ft_julia_2(t_all *all);
void				ft_julia3_1(t_all *all);
int					ft_julia3_2(t_all *all);
void				ft_mandelbrot_1(t_all *all);
int					ft_mandelbrot_2(t_all *all);
void				ft_window(int code, t_all *all);
void				ft_find_fract(char *str, t_all *all);
void				move_xy(t_all *all, double param);
void				ft_change_blue(t_all *all, double param);
void				ft_change_green(t_all *all, double param);
void 				ft_change_red(t_all *all, double param);
void				ft_std_fract_data(t_all *all);
void				draw_pixel(int x, int y, t_all *all);
void				changed_fract(t_all *all);

#endif