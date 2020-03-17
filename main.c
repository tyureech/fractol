/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:28:12 by mmahasim          #+#    #+#             */
/*   Updated: 2020/03/15 16:28:14 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int		ft_color(int iter, double iteration_max, t_34 *t34)
{
	double t;
	double t1;
	int color;
	int color2;

	t = ((double)iter / iteration_max);
	if (t > 0.99 && t34->flag != 3)
		return (0);
//	if (t < 0.15 && t34->flag == 3)
//		return (0x013921);
	color = t * 0x0745734f + t34->col;
	color2 = (int) (t * 0x830047 * t34->col);
	return (color << t34->col | color2 << 16);
}

t_m		init_complex(double re, double im)
{
	t_m complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	init_fractal(t_34 *t34)
{
	t34->col = 2;
//	t34->col = 33687909;
	t34->space = 0;
	t34->iteration_max = 50;
	t34->flag_color = 0;
	t34->k = init_complex(-0.4, 0.6);
	t34->min = init_complex( -2 , -2);
	t34->max.re = 2;
	t34->max.im = t34->min.im + (t34->max.re - t34->min.re) * HEIGHT / WIDTH;
	t34->factor = init_complex(
			(t34->max.re - t34->min.re) / (WIDTH - 1),
			(t34->max.im - t34->min.im) / (HEIGHT - 1));
}

void	ft_mlx(t_34 *t34)
{
	t34->mlx_ptr = mlx_init();
	t34->win_ptr = mlx_new_window(t34->mlx_ptr, HEIGHT, WIDTH, "fractol");
	t34->img_ptr = mlx_new_image(t34->mlx_ptr, HEIGHT, WIDTH);
	t34->data_addr = (int *)mlx_get_data_addr(t34->img_ptr, &(t34->bits_per_pixel),
											  &(t34->size_line), &(t34->endian));
	draw(t34);
	if (t34->flag == 2)
		mlx_hook(t34->win_ptr, 6, 0, Julia_hook, t34);
	mlx_hook(t34->win_ptr, 4, 0, ft_mouse_hook, t34);
	mlx_key_hook(t34->win_ptr, ft_hook, t34);
	mlx_loop(t34->mlx_ptr);
}
int		main(int argc, char **argv)
{
	t_34 *t34;

	if (!(t34 = malloc(sizeof(t_34))))
		return 0;
	if (argc != 2)
	{
		ft_putstr("\n1. Mandelbrot\n2. Julia\n3. Zont\n\n");
		return 0;
	}
		if (!ft_strcmp(argv[1], "Mandelbrot"))
			t34->flag = 1;
		else if (!ft_strcmp(argv[1], "Julia"))
			t34->flag = 2;
		else if (!ft_strcmp(argv[1], "Zont"))
			t34->flag = 3;
		else
		{
			ft_putstr("\n1. Mandelbrot\n2. Julia\n3. Zont\n\n");
			return 0;
		}
		init_fractal(t34);
		ft_mlx(t34);
	return 0;
}
