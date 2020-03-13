/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/13 19:30:04 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_key(int key, void *param)
{
	t_all	*all;
	// double	alpha;

	// alpha = 0.0174533 * 3;
	all = (t_all*)param;

	// printf("%d\n", key);
	if (key == 53)
	{
		ft_clean(all);
		exit(0);
	}
	else if (key == 49)
	{
		all->zoom += 0.2;
		// all->x_mouse = (all->w ) / 2;
		// all->y_mouse = (all->h ) / 2;
		// printf("%f\n", all->zoom);
	}
	else if (key == 126)
		all->bias_y += 10;
	else if (key == 125)
		all->bias_y -= 10;
	else
		return (0);
	//scale_keys(all, key);
	mlx_clear_window(all->image->mlx_ptr, all->image->win_ptr);
	ft_bzero(all->image->data_addr, WIDTH * 4 * HEIGHT);  //для отрисовки
	ft_cook(all);
	// pthread_create(&all->tid,&all->attr,ft_cook, all);
	// pthread_join(all->tid,NULL);
	// else if (key == 96)
	// 	ft_default(all->fdf);
	// else if (key == 51)
	// {
	// 	mlx_clear_window(all->im->mlx_ptr, all->im->win_ptr);
	// 	ft_put_text(all->im, all->fdf);
	// 	return (0);
	// }
	// else if (key == 36)
	// {
	// 	ft_default(all->fdf);
	// 	ft_bias(all->fdf);
	// }
	// rotate_keys(all, alpha, key);
	// scale_keys(all, key);
	// mlx_clear_window(all->im->mlx_ptr, all->im->win_ptr);
	// ft_show(all->im, all->fdf, all->fdf->rotate_x);
	// if (key == 42)
	// 	ft_surprise(all);
	return (0);
}

void	scale_keys(t_all *all, int key)
{
	// if (key == 69)
	// {
	// 	all->fdf->scale += all->fdf->scale_default / 4.0;
	// 	all->fdf->scale_z += all->fdf->scale_default / 4.0;
	// }
}
