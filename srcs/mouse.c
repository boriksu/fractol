/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/10 15:02:32 by dholiday         ###   ########.fr       */
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
    ft_cook(all);
	return (0);
}
