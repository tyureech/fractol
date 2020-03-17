/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:43:10 by mmahasim          #+#    #+#             */
/*   Updated: 2020/03/04 14:44:59 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include <pthread.h>
#include <math.h>
#define HEIGHT 800
#define WIDTH 800



typedef struct s_m
{
	double re;
	double im;
}				t_m;


typedef struct	s_t34
{
	void 		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int 		*data_addr;
    int			bits_per_pixel;
	int			size_line;
	int 		endian;
	t_m			min;
	t_m			max;
	t_m			factor;
	t_m			c;
	t_m			z;
	t_m			k;
	t_m			mouse;
	double		key;
	double		key2;
	double		lr;
	double		ub;
	double		zoom;
	int			start;
	int			space;
	int			and;
	int			flag;
	int			flag_color;
	int			julia;
	int			col;
	double 		iteration_max;
	int			color;
	int			color2;
}				t_34;

//typedef struct s_max
//{
//	double re;
//	double im;
//}				max;

void			init_fractal(t_34 *t34);
int				draw(t_34 *t34);
t_m				init_complex(double re, double im);
int				Mandelbrot(t_34 *t34);
int				julia(t_34 *t34);
int				ft_hook(int key, t_34 *t34);
int				ft_color(int iter, double itertation_max, t_34 *t34);
int				ft_hook(int key, t_34 *t34);
int				ft_mouse_hook(int key, int x, int y, t_34 *t34);
int				Julia_hook(int x, int y, t_34 *t34);
int				Zont(t_34 *t34);
int				Drevniy(t_34 *t34);

#endif
