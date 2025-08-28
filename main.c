/*
I have 2 kinds of fractals in mind:
the Mandelbrot set and the Julia set.

-> ./fractol mandelbrot
-> ./fractol julia

*/

#include "fractol.h"

typedef struct s_complex
{
    double real;
    double i;
}   t_complex;

int main(int argc, char **argv)
{
    t_fractal fractal;

    //void *mlx;
    //void *win;

    //mlx = mlx_init();
    //win = mlx_new_window(mlx, 800, 600, "Fractol");
    //mlx_loop(mlx);

    if (argc == 2 && (strncmp(argv[1], "mandelbrot", 11) == 0 || strncmp(argv[1], "julia", 5) == 0))
    {
        //Correct

        //1
        fractal_init(&fractal);
        //2
        fractal_render(&fractal);
        //3
        mlx_loop(fractal.mlx);
    }
    else
    {
        printf("\nError\n");
        exit(1);
    }
}
