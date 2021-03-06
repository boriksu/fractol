/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/14 19:10:36 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_all *all)
{
	all->image = (t_ptr*)malloc(sizeof(t_ptr));
	if (!(all->image))
		ft_error("problem with mAlLoC", -1, all);
	all->image->mlx_ptr = mlx_init();
	all->image->win_ptr = mlx_new_window(all->image->mlx_ptr, (WIDTH + LEGEND),
			HEIGHT, "good morning");
	all->image->img_ptr = mlx_new_image(all->image->mlx_ptr, WIDTH, HEIGHT);
	all->image->data_addr = mlx_get_data_addr(all->image->img_ptr,
						&(all->image->bits_per_pixel),
							&(all->image->size_line), &(all->image->endian));
}

void	ft_init_fractol(t_all *all)
{
	all->map[0] = ft_strdup("Mandelbrot");
	all->map[1] = ft_strdup("Julia");
	all->map[2] = ft_strdup("Buffalo");
	all->image = NULL;
	all->move = 0;
	all->zoom = 1.0;
	all->w = WIDTH;
	all->h = HEIGHT;
	all->bias_y = 0;
	all->bias_x = 0;
	all->color = 1;
	all->k = init_complex(0.5, 0.6);
	all->frac[0] = &mandelbrot;
	all->frac[1] = &julia;
	all->frac[2] = &buffalo;
}

void	ft_init_cook(t_all *all)
{
	all->min = init_complex(-2.0, -2.0);
	all->max = init_complex(2.0, 2.0);
	all->factor = init_complex(
		(all->max.re - all->min.re) / (all->zoom * all->w),
		(all->max.im - all->min.im) / (all->zoom * all->h));
}
