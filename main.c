#include <stdio.h>
#include "fractol.h"
#include <math.h>


int	ft_hook(int key, t_34 *t34)
{
	printf("%d", key);
	if (key == 53)
		exit (0);
	if (key == 1)
		t34->min.im -= 0.5;
	if (key == 0)
	{
		t34->factor.re += (double)(HEIGHT * 0.0000005);
		t34->factor.im += (double)(HEIGHT * 0.0000005);
	}
	if (key == 2)
	{
		t34->factor.re -= (double)(HEIGHT * 0.0000005);
		t34->factor.im -= (double)(HEIGHT * 0.0000005);
	}
	if (key == 124)
		t34->min.re -= t34->factor.re * 50;
	if (key == 123)
		t34->min.re += t34->factor.re * 50;
	if (key == 125)
		t34->max.im += t34->factor.im * 50;
	if (key == 126)
		t34->max.im -= t34->factor.im * 50;


	mlx_clear_window(t34->mlx_ptr, t34->win_ptr);
	ft_paralel(t34);
	printf("%d", key);
	return 0;
}


int ft_color(int iter, int max_iter)
{
	double t;

	int color;
	int color2;
	t = ((double)iter / (double)max_iter);
	if (t == 1)
		return 0;
//	if (t < 0.3)
//		return 0;
	color = (int)(t * 0x1ff);
	color2 = (int)(t * 0x444);

	return (color << 8 | color2);
}

t_m		init_complex(double re, double im)
{
	t_m complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int				ft_test2(t_34 *t34)
{
	int		y;
	int		x;
	int 	iteration;
	int		max_iteration;

	max_iteration = 50;
	y = t34->start;
	while (y < t34->and)
	{
		t34->c.im = t34->max.im - y * t34->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			t34->c.re = t34->min.re + x * t34->factor.re;
			t34->z = init_complex(t34->c.re, t34->c.im);
			iteration = 0;
			while (pow(t34->z.re, 2.0) + pow(t34->z.im, 2.0) <= 4
				   && iteration < max_iteration)
			{
				t34->z = init_complex(
						pow(t34->z.re, 2.0) - pow(t34->z.im, 2.0) + t34->c.re,
						2.0 * t34->z.re * t34->z.im + t34->c.im);
				iteration++;
			}
			mlx_pixel_put(t34->mlx_ptr, t34->win_ptr, x, y, ft_color(iteration, max_iteration));
			//t34->data_addr[y * WIDTH + x] = ft_color(iteration, max_iteration);
			x += 1;
		}
		y += 1;
	}
	//mlx_put_image_to_window(t34->mlx_ptr, t34->win_ptr, t34->img_ptr, 0, 0);
	return 0;
}

int ft_paralel(t_34 *t34)
{
	int					i;
	pthread_t			t[50];
	t_34				d_t[50];


//	t34->factor = init_complex(
//			(t34->max.re - t34->min.re) / (WIDTH - 1),
//			(t34->max.im - t34->min.im) / (HEIGHT - 1));
	i = 0;
	while (i < 50)
	{
//		d_t[i] = *t34;
//		d_t[i].start = HEIGHT * i / 50;
//		d_t[i].and = HEIGHT * (i + 1) / 50;
		t34->start = HEIGHT * i / 50;
		t34->and = HEIGHT * (i + 1) / 50;
		ft_test2(t34);
//		pthread_create(&t[i], NULL,
//						   (void *(*)(void *))ft_test2(t34), (void *)&d_t[i]);
//			return 0;
		//ft_test2(t34);
//		mlx_put_image_to_window(t34->mlx_ptr, t34->win_ptr, t34->img_ptr, 0, 0);
		i++;
	}
//	mlx_put_image_to_window(t34->mlx_ptr, t34->win_ptr, t34->img_ptr, 0, 0);
//	while (i-- > 0)
//	{
//		if (pthread_join(t[i], NULL))
//			return 0;
//	}
	return (0);
}

int main()
{
	t_34 *t34;

	if (!(t34 = malloc(sizeof(t_34))))
		return 0;
	printf("Hello, World!\n");
	t34->min = init_complex( -2 , -2);
	t34->max.re = 2;
	t34->max.im = t34->min.im + (t34->max.re - t34->min.re) * HEIGHT / WIDTH;
	t34->factor = init_complex(
			(t34->max.re - t34->min.re) / (WIDTH - 1),
			(t34->max.im - t34->min.im) / (HEIGHT - 1));


	t34->mlx_ptr = mlx_init();
	t34->win_ptr = mlx_new_window(t34->mlx_ptr, HEIGHT, WIDTH, "fractol");
	t34->img_ptr = mlx_new_image(t34->mlx_ptr, HEIGHT, WIDTH);
    t34->data_addr = (int *)mlx_get_data_addr(t34->img_ptr, &(t34->bits_per_pixel),
                                       &(t34->size_line), &(t34->endian));
    ft_paralel(t34);
//	mlx_put_image_to_window(t34->mlx_ptr, t34->win_ptr, t34->img_ptr, 0, 0);
//	ft_test2(t34);
	//printf("%lf", pow(6.0, 2.0));
	//mlx_mouse_hook(t34->win_ptr, ft_hook, t34);
	mlx_key_hook(t34->win_ptr, ft_hook, t34);
	mlx_loop(t34->mlx_ptr);
	return 0;
}