/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/10 15:23:42 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(t_complex *z, t_complex c, t_complex *k)
{
	int iteration;
	
	iteration = 0;
	while (pow(z->re, 2.0) + pow(z->im, 2.0) <= 4 && iteration < MAX_ITERATION)
	{
		*z = init_complex(
			pow(z->re, 2.0) - pow(z->im, 2.0) + c.re,
			2.0 * z->re * z->im + c.im);
		iteration++;
	}
	return (iteration);
}


int		julia(t_complex *z, t_complex c, t_complex *k)
{
	int iteration;

	iteration = 0;
	while (pow(z->re, 2.0) + pow(z->im, 2.0) <= 4 && iteration < MAX_ITERATION)
	{
		*z = init_complex(pow(z->re, 2.0) - pow(z->im, 2.0) + k->re, 2.0 * z->re * z->im + k->im);
		iteration++;
	}
	return (iteration);
}

int		buffalo(t_complex *z, t_complex c, t_complex *k)
{
	int iteration;

	iteration = 0;
	while (pow(z->re, 2.0) + pow(z->im, 2.0) <= 4	&& iteration < MAX_ITERATION)
	{
		*z = init_complex(
			fabs(pow(z->re, 2.0) - pow(z->im, 2.0)) + c.re,
			-2.0 * z->re * fabs(z->im) + c.im);
		iteration++;
	}
	return (iteration);
}
