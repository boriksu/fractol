/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/13 19:26:21 by dholiday         ###   ########.fr       */
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

void		ft_cook(t_all *all)
{
	t_test		test[FLOW];
	pthread_t	tid[FLOW];
	int			i;

	ft_init_cook(all);
	i = 0;
	while (i < FLOW)
	{
		test[i].all = all;
		test[i].y = i * (HEIGHT / FLOW);
		test[i].ye = (i + 1) * (HEIGHT / FLOW);
		if (pthread_create(&tid[i],NULL, (void *(*)(void *))ft_test, (void *)&test[i]))
			printf("a ");
		i++;
	}
	while (i-- > 0)
	{
		if (pthread_join(tid[i],NULL))
			printf("f ");
	}
	mlx_put_image_to_window(all->image->mlx_ptr, all->image->win_ptr,
						all->image->img_ptr, 0, 0);
}

void ft_test(void *param)
{
	t_complex	z;
	t_complex	c;
	int			y;
	t_test		*test;
	t_all *all;

	test = (t_test*)param;
	all = test->all;
	y = test->y;
	while (y < test->ye)
	{
		c.im = all->max.im - (y + all->bias_y) * all->factor.im;
		test->x = 0;
		while (test->x < WIDTH)
		{
			c.re = all->min.re + (test->x + all->bias_x) * all->factor.re;
			z = init_complex(c.re, c.im);
			test->iteration = all->frac[all->num](&z, c, &all->k);
			color(test->iteration, test->x, y, all);
			test->x++;
		}
		y++;
	}
}
