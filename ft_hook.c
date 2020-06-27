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

int		ft_hook(int key, t_34 *t34)
{
	if (key == 53)
		exit(0);
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
	if (key == 24)
		t34->iteration_max += 1;
	if (key == 27)
		t34->iteration_max -= 1;
	if (key == 35)
		t34->flag_psiho++;
	if (key == 18)
		t34->mode++;
	if (t34->mode == 5)
		t34->mode = 1;
	draw_flow(t34);
	return (0);
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	ft_mouse_cursor(t_34 *t34, int x, int y, int key)
{
	t34->mouse = init_complex((double)x /
			(WIDTH / (t34->max.re - t34->min.re))
			+ t34->min.re,
			(double)y / (HEIGHT / (t34->max.im - t34->min.im))
			* -1 + t34->max.im);
	if (key == 4)
		t34->zoom = 0.80;
	if (key == 5)
		t34->zoom = 1.20;
	t34->interpolation = 1.0 / t34->zoom;
	t34->min.re = interpolate(t34->mouse.re, t34->min.re, t34->interpolation);
	t34->min.im = interpolate(t34->mouse.im, t34->min.im, t34->interpolation);
	t34->max.re = interpolate(t34->mouse.re, t34->max.re, t34->interpolation);
	t34->max.im = interpolate(t34->mouse.im, t34->max.im, t34->interpolation);
	t34->factor = init_complex(
			(t34->max.re - t34->min.re) / (WIDTH - 1),
			(t34->max.im - t34->min.im) / (HEIGHT - 1));
	if (t34->flag_psiho % 2 == 1)
		if (key == 5 && t34->factor.re <= 0.000001)
			t34->iteration_max += 2;
	if (t34->flag_psiho % 2 == 1)
		if (key == 4 && t34->factor.re <= 0.000001)
			t34->iteration_max -= 2;
}

int		ft_mouse_hook(int key, int x, int y, t_34 *t34)
{
	if (key == 4 || key == 5)
	{
		ft_mouse_cursor(t34, x, y, key);
	}
	if (key == 1)
		t34->col += 1;
	if (key == 2 && t34->col > 1)
		t34->col -= 1;
	if (key == 3)
	{
		t34->flag++;
		if (t34->flag == 4)
			t34->flag = 1;
		if (t34->flag == 2)
			mlx_hook(t34->win_ptr, 6, 0, julia_hook, t34);
		init_fractal(t34);
	}
	draw_flow(t34);
	return (0);
}

int		julia_hook(int x, int y, t_34 *t34)
{
	if ((t34->space % 2) == 0)
		t34->k = init_complex(2 * ((double)x / WIDTH - 0.5),
			2 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	draw_flow(t34);
	return (0);
}
