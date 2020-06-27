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
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>
# define HEIGHT	800
# define WIDTH	800

typedef	struct	s_m
{
	double		re;
	double		im;
}				t_m;

typedef struct	s_t34
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_m			min;
	t_m			max;
	t_m			factor;
	t_m			c;
	t_m			z;
	t_m			k;
	t_m			mouse;
	int			space;
	int			flag;
	int			flag_psiho;
	int			col;
	double		iteration_max;
	double		interpolation;
	double		zoom;
	double		iteration;
	double		run;
	int			mode;
	int			par;
	int			start;
	int			finish;
}				t_34;

void			init_fractal(t_34 *t34);
void			ft_mlx(t_34 *t34);
void			draw(t_34 *t34);
t_m				init_complex(double re, double im);
void			mandelbrot(t_34 *t34);
void			julia(t_34 *t34);
int				ft_color(t_34 *t34);
int				ft_hook(int key, t_34 *t34);
int				ft_mouse_hook(int key, int x, int y, t_34 *t34);
int				julia_hook(int x, int y, t_34 *t34);
double			interpolate(double start, double end, double interpolation);
void			ft_mouse_cursor(t_34 *t34, int x, int y, int key);
void			burning_ship(t_34 *t34);
void			ft_mouse_cursor(t_34 *t34, int x, int y, int key);
void			draw_flow(t_34 *t34);
void			draw_flow(t_34 *t34);

#endif
