/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/10 15:02:02 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_print_variant(t_all *all)
{
	int i;

	ft_putstr(ANSI_COLOR_CYAN "You can choose one fractol of list below:\n\n" ANSI_COLOR_RESET);
	i = 0;
	while (i < NUMBER)
	{
		ft_printf("%d) %s\n", i + 1, all->map[i]);
		i++;
	}
	ft_error("", 0, all);
}

void	ft_error(char *str, int i, t_all *all)
{
	ft_clean(all);
	if (i == -1)
		ft_printf("\033[31;1;4m%s\033[0m\n", str);
	else
		ft_printf("%s\n", str);
	
	exit(i);
}
