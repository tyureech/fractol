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

void	draw_flow(t_34 *t34)
{
	pthread_t	threads[t34->par];
	t_34		t34_copy[t34->par];
	int			i;

	i = 0;
	mlx_clear_window(t34->mlx_ptr, t34->win_ptr);
	mlx_destroy_image(t34->mlx_ptr, t34->img_ptr);
	if (!(t34->img_ptr = mlx_new_image(t34->mlx_ptr, HEIGHT, WIDTH)))
		exit(5);
	while (i < t34->par)
	{
		t34_copy[i] = *t34;
		t34_copy[i].start = i * (HEIGHT / t34->par);
		t34_copy[i].finish = (i + 1) * (HEIGHT / t34->par);
		if (pthread_create(&threads[i], NULL,
				(void *(*)(void *)) draw, (void *)&t34_copy[i]))
			exit(10);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			exit(10);
	mlx_put_image_to_window(t34->mlx_ptr, t34->win_ptr, t34->img_ptr, 0, 0);
}

t_m		init_complex(double re, double im)
{
	t_m		complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	init_fractal(t_34 *t34)
{
	t34->col = 1;
	t34->space = 0;
	t34->iteration_max = 50;
	t34->flag_psiho = 0;
	t34->k = init_complex(9, 1);
	t34->min = init_complex(-2, -2);
	t34->max.re = 2;
	t34->max.im = t34->min.im + (t34->max.re - t34->min.re) * HEIGHT / WIDTH;
	t34->factor = init_complex(
			(t34->max.re - t34->min.re) / (WIDTH - 1),
			(t34->max.im - t34->min.im) / (HEIGHT - 1));
	t34->par = 10;
}

void	ft_mlx(t_34 *t34)
{
	if (!(t34->mlx_ptr = mlx_init()) ||
	!(t34->win_ptr = mlx_new_window(t34->mlx_ptr, HEIGHT, WIDTH, "Fract'ol"))
	|| !(t34->img_ptr = mlx_new_image(t34->mlx_ptr, HEIGHT, WIDTH)) ||
	!(t34->data_addr = (int *)mlx_get_data_addr(t34->img_ptr,
			&(t34->bits_per_pixel), &(t34->size_line), &(t34->endian))))
		exit(5);
	draw_flow(t34);
	if (t34->flag == 2)
		mlx_hook(t34->win_ptr, 6, 0, julia_hook, t34);
	mlx_hook(t34->win_ptr, 4, 0, ft_mouse_hook, t34);
	mlx_key_hook(t34->win_ptr, ft_hook, t34);
	mlx_loop(t34->mlx_ptr);
	free(t34);
}

int		main(int argc, char **argv)
{
	t_34	*t34;

	if (!(t34 = malloc(sizeof(t_34))))
		return (0);
	if (argc != 2)
	{
		ft_putstr("\n1. Mandelbrot\n2. Julia\n3. Burning Ship\n\n");
		return (0);
	}
	if (!ft_strcmp(argv[1], "Mandelbrot") || !ft_strcmp(argv[1], "1"))
		t34->flag = 1;
	else if (!ft_strcmp(argv[1], "Julia") || !ft_strcmp(argv[1], "2"))
		t34->flag = 2;
	else if (!ft_strcmp(argv[1], "Burning Ship") || !ft_strcmp(argv[1], "3"))
		t34->flag = 3;
	else
	{
		ft_putstr("\n1. Mandelbrot\n2. Julia\n3. Burning Ship\n\n");
		return (0);
	}
	init_fractal(t34);
	ft_mlx(t34);
	return (0);
}
