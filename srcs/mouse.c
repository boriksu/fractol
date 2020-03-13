/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/13 19:26:18 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, void *param)
{
	t_all	*all;
    t_complex k;
	int		i;

	i = 0;
	all = (t_all*)param;
	if (all->move == 0)
		return (0);
	all->k = init_complex(4 * ((double)x / WIDTH - 0.5), 4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	mlx_clear_window(all->image->mlx_ptr, all->image->win_ptr);
	ft_bzero(all->image->data_addr, WIDTH * 4 * HEIGHT);  //для отрисовки
	ft_cook(all);
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_all *all;

	all = (t_all*)param;
	if (button == 5)
	{
		all->zoom += 0.2;
		all->bias_x = (all->zoom * all->w - WIDTH) / 2;
		all->bias_y = (all->zoom * all->h - HEIGHT) / 2;
	}
	else if (button == 4)
	{
		if (all->zoom > 0.15)
			all->zoom -= 0.1;
		all->bias_x = (all->zoom * all->w - WIDTH) / 2;
		all->bias_y = (all->zoom * all->h - HEIGHT) / 2;
		// printf("%f\n", all->zoom);
	}
	else
		return (0);
	mlx_clear_window(all->image->mlx_ptr, all->image->win_ptr);
	ft_bzero(all->image->data_addr, WIDTH * 4 * HEIGHT);  //для отрисовки
	ft_cook(all);
	return (0);
}
