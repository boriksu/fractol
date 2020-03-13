/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/13 16:36:14 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void		ft_cook(void *param)
{
	t_complex	z;
	t_complex	c;
	int			iteration;
	int			x;
	int			y;
	t_all *all = param;
	t_test test[FLOW];
	pthread_t	tid[FLOW];

	ft_init_cook(all);

	printf("b _x = %f | b _y = %f\n\n", (all->zoom * all->w - WIDTH) / 2 + all->x_mouse - WIDTH / 2,
												(all->zoom * all->h - HEIGHT) / 2  + all->y_mouse - HEIGHT / 2);

	int i;

	// test.all = all;
	i = 0;
	while (i < FLOW)
	{
		test[i].all = all;
		test[i].bias_x = (test->all->zoom * test->all->w - WIDTH) / 2 ; //+ all->x_mouse - WIDTH / 2;
		test[i].bias_y = (test->all->zoom * test->all->h - HEIGHT) / 2; // + all->y_mouse - HEIGHT / 2;
		
		test[i].y = i * (HEIGHT / FLOW);
		test[i].ye = (i + 1) * (HEIGHT / FLOW);
		if (pthread_create(&tid[i],NULL, (void *(*)(void *))ft_test, (void *)&test[i]))
			printf("a ");
		i++;
	}

	// printf("\n");

	while (i-- > 0)
	{
		if (pthread_join(tid[i],NULL))
			printf("f ");
	}




	// y = 0;
	// while (y < HEIGHT)
	// {
	// 	c.im = all->max.im - y * all->factor.im;
	// 	x = 0;
	// 	while (x < WIDTH)
	// 	{
	// 		c.re = all->min.re + x * all->factor.re;
	// 		z = init_complex(c.re, c.im);
	// 		iteration = all->frac[all->num](&z, c, &all->k);
	// 		color(iteration, x, y, all);
	// 		x++;
	// 	}
	// 	y++;
	// }
	mlx_put_image_to_window(all->image->mlx_ptr, all->image->win_ptr,
						all->image->img_ptr, 0, 0);
	// pthread_exit(0);
}

void ft_test(void *param)
{
	t_complex	z;
	t_complex	c;
	int			iteration;
	int			x;
	int			y;
	t_test *test = param;

	int bias_x;
	int bias_y;

	// bias_x = (test->all->zoom * test->all->w - WIDTH) / 2;
	// bias_y = (test->all->zoom * test->all->h - HEIGHT) / 2;

	// bias_x = test->all->x_mouse - WIDTH / 2;
	// bias_y = test->all->y_mouse - HEIGHT / 2;

	//printf("k ");
	y = test->y;
	while (y < test->ye)
	{
		c.im = test->all->max.im - (y + test->bias_y) * test->all->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			c.re = test->all->min.re + (x + test->bias_x) * test->all->factor.re;
			z = init_complex(c.re, c.im);
			iteration = test->all->frac[test->all->num](&z, c, &test->all->k);
			color(iteration, x, y, test->all);
			x++;
		}
		y++;
	}
}
