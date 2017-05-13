/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhorbach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:27:51 by vhorbach          #+#    #+#             */
/*   Updated: 2017/04/24 21:12:59 by vhorbach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_window(int code, t_all *all)
{
	all->mlx.mlx = mlx_init();
	ft_std_fract_data(all);
	if (code == 1)
	{
		all->mlx.win = mlx_new_window(all->mlx.mlx,
							WIN_WID, WIN_HIGH, "Julia");
		ft_threads(all);
	}
	else if (code == 2)
	{
		all->mlx.win = mlx_new_window(all->mlx.mlx,
						WIN_WID, WIN_HIGH, "Mandelbrot");
		ft_threads(all);
	}
	else if (code == 3)
	{
		all->mlx.win = mlx_new_window(all->mlx.mlx,
							WIN_WID, WIN_HIGH, "Julia^3");
		ft_threads(all);
	}
	mlx_hook(all->mlx.win, 2, 3, key_hook, all);
	mlx_mouse_hook(all->mlx.win, mouse_hook, all);
	mlx_loop(all->mlx.mlx);
}

void	say_error(int code)
{
	if (code == 1)
	{
		ft_putstr("usage:\n");
		ft_putstr("       The number of arguments must be from 1 to 3\n");
	}
	else if (code == 2)
	{
		ft_putstr("usage:\n");
		ft_putstr("       If you want the Mandelbrot set displayed - "
							"type 'M' as argument.\n");
		ft_putstr("       If you want the Julia set displayed - "
							"type 'J' as argument.\n");
		ft_putstr("       If you want the Julia^3 set displayed - "
							"type 'J3' as argument.\n");
		ft_putstr("       If you want all of these sets displayed - "
							"use all mentioned arguments. Thank's, Captain!\n");
	}
	else
		ft_putstr("A long time ago, in a galaxy far, far away..."
							"Fract'ol crashed!\n");
	exit(0);
}

void	ft_find_fract(char *str, t_all *all)
{
	all->fract.mouse = 1;
	if (ft_strcmp(str, "J") == 0)
	{
		all->fract.flag = 1;
		ft_window(1, all);
	}
	else if (ft_strcmp(str, "M") == 0)
	{
		all->fract.flag = 2;
		ft_window(2, all);
	}
	else if (ft_strcmp(str, "J3") == 0)
	{
		all->fract.flag = 3;
		ft_window(3, all);
	}
	else
		say_error(2);
}

int		main(int ac, char **av)
{
	int		i;
	pid_t	pid;
	t_all	*all;

	i = 1;
	all = (t_all *)malloc(sizeof(t_all));
	all->p.flag = 0;
	all->fract.flag = 0;
	if (ac < 2 || ac > 4)
		say_error(1);
	else
	{
		while (i < ac)
		{
			pid = fork();
			if (pid != 0)
			{
				all->fract.string = av[i];
				ft_find_fract(all->fract.string, all);
				break ;
			}
			i++;
		}
	}
	return (0);
}
