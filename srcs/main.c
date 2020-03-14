/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/14 19:15:12 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_all all;

	ft_init_fractol(&all);
	if (argc > 2)
		ft_error("Please, choose only one fractol", 0, &all);
	else if (argc == 1)
		ft_print_variant(&all);
	else
		understand(&all, argv);
	mlx_key_hook(all.image->win_ptr, deal_key, &all);
	mlx_hook(all.image->win_ptr, 6, 0, mouse_move, &all);
	mlx_hook(all.image->win_ptr, 4, 0, mouse_press, &all);
	mlx_loop(all.image->mlx_ptr);
	return (0);
}

void	understand(t_all *all, char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0 || ft_strcmp(argv[1], "1") == 0)
		all->num = 0;
	else if (ft_strcmp(argv[1], "Julia") == 0 || ft_strcmp(argv[1], "2") == 0)
	{
		all->move = 1;
		all->num = 1;
	}
	else if (ft_strcmp(argv[1], "Buffalo") == 0 || ft_strcmp(argv[1], "3") == 0)
		all->num = 2;
	else
	{
		ft_putstr(ANSI_COLOR_BLUE "Look again the list ⇓⇓⇓\n" ANSI_COLOR_RESET);
		ft_print_variant(all);
		return ;
	}
	ft_putstr(ANSI_COLOR_YELLOW "Good choice!\n" ANSI_COLOR_RESET);
	ft_init(all);
	ft_bzero(all->image->data_addr, WIDTH * 4 * HEIGHT);
	ft_cook(all);
	ft_put_text(all);
}
