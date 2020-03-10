/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/10 15:04:41 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(int iteration, int x, int y, t_all *all)
{
	double t;
	int red;
	int green;
	int blue;
	int i;

	t = (double)iteration / (double)MAX_ITERATION;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
	i = (x * all->image->bits_per_pixel / 8) + (y * all->image->size_line);
	record_color(all, i, red, green, blue);
}

void	record_color(t_all *all, int i, int red, int green, int blue)
{
	all->image->data_addr[i] = blue; // B — Blue
	all->image->data_addr[++i] = green; // G — Green
	all->image->data_addr[++i] = red; // R — Red
	all->image->data_addr[++i] = 0;
}
