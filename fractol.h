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
#define HEIGHT 500
#define WIDTH 500



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
	double		key;
	double		key2;
	double		lr;
	double		ub;
	int			start;
	int			and;
}				t_34;

//typedef struct s_max
//{
//	double re;
//	double im;
//}				max;

int				ft_hook(int key, t_34 *t34);
int				ft_test(t_34 *t34);
int				ft_color(int iter, int max_iter);
int				ft_test2(t_34 *t34);
t_m				init_complex(double re, double im);
int				ft_paralel(t_34 *t34);

#endif
