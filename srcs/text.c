/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/14 20:00:08 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_text(t_all *all)
{
	int			y;
	void		*mlx;
	void		*win;

	y = -10;
	mlx = all->image->mlx_ptr;
	win = all->image->win_ptr;
	mlx_string_put(mlx, win, (WIDTH), y += 25, 0xffffff, "Hello!");
	mlx_string_put(mlx, win, (WIDTH), y += 25, 0xffffff,
								"This is instruction how ");
	mlx_string_put(mlx, win, (WIDTH), y += 25,
			0xffffff, "to use this awesome Fractol:");
	mlx_string_put(mlx, win, (WIDTH), y += 50, 0xffffff, "ESCape - exit");
	mlx_string_put(mlx, win, (WIDTH), y += 25, 0xffffff, "F5 - initial image");
	mlx_string_put(mlx, win, (WIDTH), y += 25, 0xffffff, "SPACE - zoom in");
	mlx_string_put(mlx, win, (WIDTH), y += 25, 0xffffff,
								"mouse wheel up - zoom in");
	mlx_string_put(mlx, win, (WIDTH), y += 25, 0xffffff,
							"mouse wheel down - zoom out");
	mlx_string_put(mlx, win, (WIDTH), y += 25,
			0xffffff, "left / right - X-axis move");
	mlx_string_put(mlx, win, (WIDTH), y += 25,
			0xffffff, "up / down - Y-axis move");
	ft_put_text2(all, y);
}

void	ft_put_text2(t_all *all, int y)
{
	void		*mlx;
	void		*win;

	mlx = all->image->mlx_ptr;
	win = all->image->win_ptr;
	mlx_string_put(mlx, win, (WIDTH), y += 35, 0xffffff, "C - another color");
	mlx_string_put(mlx, win, (WIDTH), y += 25, 0xffffff,
							"S - put on sunglasses (on/off)");
	mlx_string_put(mlx, win, (WIDTH), y += 30, 0xffffff, "Enjoy it!");
}
