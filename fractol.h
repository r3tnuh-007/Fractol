/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 03:31:45 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//perror
# include <stdio.h>
//malloc
# include <stdlib.h>
//fabs
# include <math.h>
//write
# include <unistd.h>
//keysymbols such as XK_Escape...
# include <X11/keysym.h>
//KeyPress and KeyPressMask
# include <X11/X.h>
//All minilibx funtions that I used
# include "minilibx-linux/mlx.h"
//Error message
# define ERROR_MESSAGE "Please enter\n\t\"mandelbrotset\"\n\t\"julia <r> <i>\""
//Size of a window
# define WIDTH 742
# define HEIGHT 642
//Color
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
//Psychedelic color
# define MAGENTA_BURST 0xFF00FF
# define LIME_SHOCK 0xCCFF00
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF

typedef struct s_image
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*win;
	t_image	img;
	double	escape_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	int		max_iterations;
}			t_fractal;

typedef struct s_complex
{
	double	real;
	double	i;
}			t_complex;

//str funtions
int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);
//init funtions
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
//math functions
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
//handle functions
int			key_handle(int keysym, t_fractal *fractal);
int			close_handle(t_fractal *fractal);
int			mouse_handle(int button, int x, int y, t_fractal *fractal);
//render functions
void		fractal_render(t_fractal *fractal);
void		handle_pixel(int x, int y, t_fractal *fractal);
void		my_pixel_put(t_image *img, int x, int y, int color);
#endif
