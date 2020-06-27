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
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_34 *t34)
{
	int		y;
	int		x;

	y = t34->start;
	while (y < t34->finish)
	{
		t34->c.im = t34->max.im - y * t34->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			t34->c.re = t34->min.re + x * t34->factor.re;
			t34->z = init_complex(t34->c.re, t34->c.im);
			if (t34->flag == 1)
				mandelbrot(t34);
			else if (t34->flag == 2)
				julia(t34);
			else if (t34->flag == 3)
				burning_ship(t34);
			t34->data_addr[y * WIDTH + x] = ft_color(t34);
			x += 1;
		}
		y += 1;
	}
}

void	julia(t_34 *t34)
{
	t34->iteration = 0;
	while ((t34->run = t34->z.re * t34->z.re + t34->z.im * t34->z.im) <= 4
	&& t34->iteration < t34->iteration_max)
	{
		t34->z = init_complex(
				t34->z.re * t34->z.re - t34->z.im * t34->z.im + t34->k.re,
				2.0 * t34->z.re * t34->z.im + t34->k.im);
		t34->iteration++;
	}
}

void	mandelbrot(t_34 *t34)
{
	t34->iteration = 0;
	t34->run = 0;
	while ((t34->run = t34->z.re * t34->z.re + t34->z.im * t34->z.im) <= 4
	&& t34->iteration < t34->iteration_max)
	{
		t34->z = init_complex(
				t34->z.re * t34->z.re - t34->z.im * t34->z.im + t34->c.re,
				2.0 * t34->z.re * t34->z.im + t34->c.im);
		t34->iteration++;
	}
}

void	burning_ship(t_34 *t34)
{
	t34->iteration = 0;
	while ((t34->run = t34->z.re * t34->z.re + t34->z.im * t34->z.im) <= 4
	&& t34->iteration < t34->iteration_max)
	{
		t34->z = init_complex(
				t34->z.re * t34->z.re - t34->z.im * t34->z.im + t34->c.re,
				-2.0 * fabs(t34->z.re * t34->z.im) + t34->c.im);
		t34->iteration++;
	}
}

int		ft_color(t_34 *t34)
{
	double	t;
	int		m;

	t = t34->iteration / t34->iteration_max;
	if (t > 0.99)
		return (0);
	if (t34->mode == 2)
		m = ((int)(0xfff / t34->z.re) | (int)(0xfff123 / t * t34->col));
	else if (t34->mode == 1)
		m = ((int)(0xfffff / t34->run * t * t34->col));
	else if (t34->mode == 3)
		m = ((int)(0xfff / t34->z.re * t34->col) + (int)(0xfff123
		* t34->iteration * t34->col));
	else
		m = ((int)(0xfff / t34->run * t) | (int)(0xfffff / t * t34->col));
	return (m);
}
