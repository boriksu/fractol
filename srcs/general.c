/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/10 15:19:35 by dholiday         ###   ########.fr       */
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
	t_complex	z;
	t_complex	c;
	int			iteration;
	int			x;
	int			y;

	ft_init_cook(all);
	y = 0;
	while (y < HEIGHT)
	{
		c.im = all->max.im - y * all->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			c.re = all->min.re + x * all->factor.re;
			z = init_complex(c.re, c.im);
			iteration = all->frac[all->num](&z, c, &all->k);
			color(iteration, x, y, all);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->image->mlx_ptr, all->image->win_ptr,
						all->image->img_ptr, 0, 0);
}