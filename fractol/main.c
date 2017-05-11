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

int 	mouse_hook(int button, int x, int y, t_all *all)
{
	printf("%d\n%d\n", x , y);
	if (button == 4)
	{
		all->fract.zoom = all->fract.zoom + .1;
	}
	else if (button == 5)
	{
		all->fract.zoom = all->fract.zoom - .1;
	}
	else if (button == 1)
	{
		if (all->fract.flag == 1 || all->fract.flag == 3)
		{
			all->fract.x = x;
			all->fract.y = y;
		}
//		else
//		{
//			all->fract.pr += 1;
//			all->fract.pi += 1;
//		}
	}
	ft_threads(all);
	return (0);
}

t_data	*data_create(t_all *all, t_data *d, int i)
{
	int 	lines;

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
	int 			i;
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
	//mlx_hook(all->mlx.win, 6, 2, mouse_hook, all);
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
							"type 'J1' as argument.\n");
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
	else if (ft_strcmp(str, "J1") == 0)
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
