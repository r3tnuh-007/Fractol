#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal fractal;
    if (argc == 2 && !ft_strncmp(argv[1], "mandelbrotset", 16) // to do
    || argc == 4 && !ft_strncmp(argv[1], "julia", 10))
    {
        fractal.name = argv[1];
        //1
        fractal_init(&fractal);

        //2
        //fractal_render(&fractal);

        //3
        mlx_loop(fractal.mlx);
    }
    else
    {
        putstr_fd(ERROR_MESSAGE, STDERR_FILENO); // to do
        exit(EXIT_FAILURE);

    }
}