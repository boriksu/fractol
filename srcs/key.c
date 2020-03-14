/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/14 19:14:53 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_key(int key, void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if (key == EXIT)
	{
		ft_clean(all);
		exit(0);
	}
	else if (key == ZOOM)
	{
		all->zoom += 0.2;
		all->bias_x = (all->zoom * all->w - WIDTH) / 2;
		all->bias_y = (all->zoom * all->h - HEIGHT) / 2;
	}
	else if (key == INITIAL)
	{
		all->zoom = 1.0;
		all->bias_y = 0;
		all->bias_x = 0;
	}
	else if (key_move(key, all) == 0)
		return (0);
	ft_cook(all);
	return (0);
}

int		key_move(int key, t_all *all)
{
	if (key == UP)
		all->bias_y += 50;
	else if (key == DOWN)
		all->bias_y -= 50;
	else if (key == LEFT)
		all->bias_x += 50;
	else if (key == RIGHT)
		all->bias_x -= 50;
	else if (key == COLOR && all->color > 0)
		all->color++;
	else if (key == SUN)
		all->color *= -1;
	else
		return (0);
	return (1);
}
