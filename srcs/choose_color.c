/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/14 20:06:56 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color		second_color(double t)
{
	t_color color;

	color.red = (int)(8.5 * pow((1 - t), 3) * t * 255);
	color.green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.blue = (int)(9 * (1 - t) * pow(t, 3) * 255);
	return (color);
}

t_color		third_color(double t)
{
	t_color color;

	color.red = (int)(3 * (1 - t) * pow(t, 3) * 255);
	color.green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.blue = (int)(3 * pow((1 - t), 3) * t * 255);
	return (color);
}

t_color		four_color(double t)
{
	t_color color;

	color.red = (int)(255 - 9 * (1 - t) * pow(t, 3) * 255);
	color.green = (int)(255 - 15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.blue = (int)(255 - 8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}
