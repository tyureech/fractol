/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 15:36:46 by mmahasim          #+#    #+#             */
/*   Updated: 2020/03/14 15:36:50 by mmahasim         ###   ########.fr       */
/*                                                                            */
#include "fractol.h"

/* ************************************************************************** */

int				draw(t_34 *t34)
{
	int		y;
	int		x;
	int 	iteration;

	y = 0;
	while (y < HEIGHT)
	{
		t34->c.im = t34->max.im - y * t34->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			t34->c.re = t34->min.re + x * t34->factor.re;
			t34->z = init_complex(t34->c.re, t34->c.im);
			if (t34->flag == 1)
				iteration = Mandelbrot(t34);
			else if (t34->flag == 2)
				iteration = julia(t34);
			else if (t34->flag == 3)
				iteration = Drevniy(t34);
//			if (t34->iteration_max > 50)
//				t34->data_addr[y * WIDTH + x] = ft_color(iteration * t34->iteration_max, t34);
//			else
				t34->data_addr[y * WIDTH + x] = ft_color(iteration, t34->iteration_max, t34);
			x += 1;
		}
		y += 1;
	}
	mlx_put_image_to_window(t34->mlx_ptr, t34->win_ptr, t34->img_ptr, 0, 0);
	return 0;
}

int		julia(t_34 *t34)
{
	int		iteration;

	iteration = 0;
	while (t34->z.re * t34->z.re + t34->z.im * t34->z.im <= 4
		   && iteration < t34->iteration_max)
	{
		t34->z = init_complex(
				t34->z.re * t34->z.re - t34->z.im * t34->z.im + t34->k.re,
				2.0 * t34->z.re * t34->z.im + t34->k.im);
		iteration++;
	}
	return (iteration);
}

int		Mandelbrot(t_34 *t34)
{
	int iteration;

	iteration = 0;
	while ((t34->z.re * t34->z.re + t34->z.im * t34->z.im) <= 4
	&& iteration < t34->iteration_max)
	{
		t34->z = init_complex(
				t34->z.re * t34->z.re - t34->z.im * t34->z.im + t34->c.re,
				2.0 * t34->z.re * t34->z.im + t34->c.im);
		iteration++;
	}
	return iteration;
}

int		Zont(t_34 *t34)
{
	int			iteration;

	iteration = 0;
	//t34->z = init_complex(t34->c.re, t34->c.im);
	while (t34->z.re * t34->z.re + t34->z.im * t34->z.im <= 4
		   && iteration < t34->iteration_max)
	{
		t34->z = init_complex(
				t34->z.re * t34->z.re - t34->z.im * t34->z.im + t34->c.im,
				t34->z.re * t34->z.re - t34->z.im * t34->z.im + t34->c.re);
		iteration++;
	}
	return (iteration);
}

int		Drevniy(t_34 *t34)
{
	int iteration;

	iteration = 0;
	while ((t34->z.re * t34->z.re + t34->z.im * t34->z.im) <= 4
		   && iteration < t34->iteration_max)
	{
		t34->z = init_complex(
				t34->z.re * t34->z.re - t34->z.im * t34->z.im + t34->c.re,
				2.0 * fabs(t34->z.re * t34->z.im) + t34->c.im);
		iteration++;
	}
	return iteration;
}