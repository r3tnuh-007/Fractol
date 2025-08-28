#include "fractol.h"

void fractal_init(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    fractal -> mlx = mlx_init();
    if (fractal -> mlx == NULL)
    {
        printf("Error initializing MLX\n");
        exit(1);
    }
    fractal->win = mlx_new_window(fractal->mlx, 800, 600, "Fractol");
    if (fractal -> win == NULL)
    {
        mlx_destroy_display(fractal -> mlx);
        free(fractal -> mlx);
        exit(1);
    }
    fractal -> img.img = mlx_new_image(fractal -> mlx, 800, 600);
    if (fractal -> img.img == NULL)
    {
        mlx_destroy_window(fractal -> mlx, fractal -> win);
        mlx_destroy_display(fractal -> mlx);
        free(fractal -> mlx);
        exit(1);
    }
    fractal -> img.pixel_ptr = mlx_get_data_addr(fractal -> img.img,
            &fractal -> img.bits_per_pixel, &fractal -> img.line_length,
            &fractal -> img.endian);
}

