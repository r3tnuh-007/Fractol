#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <X11/keysym.h>
#include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter\n\t\"./fractol mandelbrotset\" or \n\t\".fractol julia <r> <i>\"\n"
# define WIDTH 800
# define HEIGHT 800

typedef struct s_image
{
    void    *img_ptr;
    char    *pixel_ptr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_image;

typedef struct s_fractal
{
    char    *name;
    void    *mlx; //connection
    void    *win; //window
    t_image img;

    //Hooks variables
}   t_fractal;

typedef struct s_complex
{
    double real;
    double i;
}   t_complex;

// Strings
int ft_strncmp(char *s1, char *s2, int n);
void putstr_fd(char *s, int fd);

//Fractal
void fractal_init(t_fractal *fractal);

// Math
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

#endif
