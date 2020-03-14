/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/14 20:01:10 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_variant(t_all *all)
{
	int i;

	ft_putstr(ANSI_COLOR_CYAN "You can choose one fractol of list below:\n\n"
				ANSI_COLOR_RESET);
	i = 0;
	while (i < NUMBER)
	{
		ft_putnbr(i + 1);
		ft_putstr(") ");
		ft_putstr(all->map[i]);
		ft_putstr("\n");
		i++;
	}
	ft_error("", 0, all);
}

void	ft_error(char *str, int i, t_all *all)
{
	ft_clean(all);
	if (i == -1)
	{
		ft_putstr(ANSI_COLOR_RED "");
		ft_putstr(str);
		ft_putstr("\n" ANSI_COLOR_RESET);
	}
	else
	{
		ft_putstr(str);
		ft_putstr("\n");
	}
	exit(i);
}
