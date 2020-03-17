/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:26:00 by mmahasim          #+#    #+#             */
/*   Updated: 2020/03/15 16:26:03 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	ft_hook(int key, t_34 *t34)
{
	printf("%d\n", key);
	if (key == 53)
		exit (0);
	if (key == 124)
		t34->min.re -= t34->factor.re * 50;
	if (key == 123)
		t34->min.re += t34->factor.re * 50;
	if (key == 125)
		t34->max.im += t34->factor.im * 50;
	if (key == 126)
		t34->max.im -= t34->factor.im * 50;
	if (key == 49)
		t34->space += 1;
//	if (key == 24 && t34->factor.re <= 0.00001)
//		t34->iteration_max += 1;
	mlx_clear_window(t34->mlx_ptr, t34->win_ptr);
	draw(t34);
	return 0;
}

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int		ft_mouse_hook(int key, int x, int y, t_34 *t34)
{
	printf("%d\n", key);
	double		interpolation;
	double		zoom;

	if (key == 4 || key == 5)
	{
		t34->mouse = init_complex(
				(double) x / (WIDTH / (t34->max.re - t34->min.re))
				+ t34->min.re,
				(double) y / (HEIGHT / (t34->max.im - t34->min.im))
				* -1 + t34->max.im);
		if (key == 4)
			zoom = 0.80;
		if (key == 5)
			zoom = 1.20;
		interpolation = 1.0 / zoom;
		t34->min.re = interpolate(t34->mouse.re, t34->min.re, interpolation);
		t34->min.im = interpolate(t34->mouse.im, t34->min.im, interpolation);
		t34->max.re = interpolate(t34->mouse.re, t34->max.re, interpolation);
		t34->max.im = interpolate(t34->mouse.im, t34->max.im, interpolation);
		t34->factor = init_complex(
				(t34->max.re - t34->min.re) / (WIDTH - 1),
				(t34->max.im - t34->min.im) / (HEIGHT - 1));
		if (key == 5 && t34->factor.re <= 0.00001)
			t34->iteration_max += 0.5;
		if (key == 4 && t34->factor.re <= 0.00001)
			t34->iteration_max -= 0.5;
	}
	if (key == 1)
		t34->col += 100;
	if (key == 2)
		t34->col -= 100;
	if (key == 3)
	{
		t34->flag++;
		if (t34->flag == 4)
			t34->flag = 1;
		init_fractal(t34);
	}
	printf("\n%.15lf %lf\n", t34->factor.re, t34->iteration_max);
	mlx_clear_window(t34->mlx_ptr, t34->win_ptr);
	draw(t34);
	return 0;
}

int Julia_hook(int x, int y, t_34 *t34)
{
	if ((t34->space % 2) == 0)
	t34->k = init_complex(
			2 * ((double) x / WIDTH - 0.5),
			2 * ((double) (HEIGHT - y) / HEIGHT - 0.5));
	mlx_clear_window(t34->mlx_ptr, t34->win_ptr);
	draw(t34);
}