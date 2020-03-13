/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:53:13 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/13 19:23:39 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define NUMBER		3
# define WIDTH 		1000
# define HEIGHT 	1000
# define MAX_ITERATION 	50
# define FLOW 	100

typedef struct	s_ptr
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_ptr;

typedef struct	s_complex
{
	double re;
	double im;
}				t_complex;

typedef struct	s_all
{
	char		*map[NUMBER];
	int			move;
	int			num;
	double		zoom;
	int			w;
	int			h;
	int			bias_x;
	int			bias_y;
	t_complex	k;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_ptr		*image;
	pthread_t	tid[FLOW]; /* идентификатор потока */
  	pthread_attr_t	attr; /* отрибуты потока */
	int			(*frac[NUMBER])(t_complex *z, t_complex c, t_complex *k);
}				t_all;

typedef struct	s_test
{
	int y;
	int ye;
	int x;
	int iteration;
	t_all *all;
}				t_test;

void	ft_init(t_all *all);
void	ft_init_fractol(t_all *all);
void	ft_init_cook(t_all *all);
void	ft_clean(t_all *all);

void	understand(t_all *all, char **argv);

void	ft_print_variant(t_all *all);
void	ft_error(char *str, int i, t_all *all);

int		deal_key(int key, void *param);
int		mouse_move(int x, int y, void *param);
int		mouse_press(int button, int x, int y, void *param);

t_complex init_complex(double re, double im);
void		ft_cook(t_all *all);

int		mandelbrot(t_complex *z, t_complex c, t_complex *k);
int		julia(t_complex *z, t_complex c, t_complex *k);
int		buffalo(t_complex *z, t_complex c, t_complex *k);

// void	ft_cook2(t_all *all, t_complex *k);

// t_complex ft_square(t_complex z);
// void	ft_cook3(t_all *all);

void	color(int iteration, int x, int y, t_all *all);
void	record_color(t_all *all, int i, int red, int green, int blue);


void ft_test(void *param);

#endif
