#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter\n\t\"./fractol mandelbrotset\" or \n\t\".fractol julia <r> <i>\"\n"
# define WIDTH 742
# define HEIGHT 642

// Colors
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

// Psychedelic colors
# define MAGENTA_BURST 0xFF00FF
# define LIME_SHOCK 0xCCFF00
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF
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
    double escape_value; //hypotenuse limit to consider a value escaped
    double shift_x;
    double shift_y;
    double zoom;
    int max_iterations; //value tight with image quality and rendering speed
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
void data_init(t_fractal *fractal);
void fractal_render(t_fractal *fractal);

// Math
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

// Events
int key_handle (int keysym, t_fractal *fractal);
int close_handle(t_fractal *fractal);
int mouse_handle(int button, int x, int y, t_fractal *fractal);

#endif
