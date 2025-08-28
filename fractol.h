#ifndef FRACTOL_H
#define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"

typedef struct s_image
{
    void    *img;
    char    *pixel_ptr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_image;

typedef struct s_fractal
{
    void    *mlx; //connection
    void    *win; //window
    t_image img;
}   t_fractal;

typedef struct s_complex
{
    double real;
    double i;
}   t_complex;

#endif
