/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/14 20:06:51 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		color(int iteration, int x, int y, t_all *all)
{
	double	t;
	t_color	color;
	int		i;

	t = (double)iteration / (double)MAX_ITERATION;
	if (all->color < 0)
		color = four_color(t);
	else if (all->color % 3 == 1)
		color = first_color(t);
	else if (all->color % 3 == 2)
		color = second_color(t);
	else if (all->color % 3 == 0)
		color = third_color(t);
	i = (x * all->image->bits_per_pixel / 8) + (y * all->image->size_line);
	record_color(all, i, &color);
}

void		record_color(t_all *all, int i, t_color *color)
{
	all->image->data_addr[i] = color->blue;
	all->image->data_addr[++i] = color->green;
	all->image->data_addr[++i] = color->red;
	all->image->data_addr[++i] = 0;
}

t_color		first_color(double t)
{
	t_color color;

	color.red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	color.green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}
