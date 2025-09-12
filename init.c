#include "fractol.h"

static void malloc_error(void)
{
    perror("\nProblem with malloc\n");
    exit(EXIT_FAILURE);
}

void data_init(t_fractal *fractal)
{
    fractal -> escape_value = 8.0; // 2², my hypotenuse limit to consider a value escaped
    fractal -> max_iterations = 42; //value tight with image quality and rendering speed
    fractal -> shift_x = 0.0;
    fractal -> shift_y = 0.0;
    fractal -> zoom = 1.0;
}

static void events_init(t_fractal *fractal)
{
    mlx_hook(fractal -> win, KeyPress, KeyPressMask, key_handle, fractal);
    mlx_hook(fractal -> win, ButtonPress, ButtonPressMask, mouse_handle, fractal);
    mlx_hook(fractal -> win, DestroyNotify, StructureNotifyMask, close_handle, fractal);
}

void fractal_init(t_fractal *fractal)
{
    // Connetion
    fractal -> mlx = mlx_init();
    if (fractal -> mlx == NULL)
        malloc_error();

    // Window
    fractal -> win = mlx_new_window(fractal -> mlx, WIDTH, HEIGHT, fractal -> name);
    if (fractal -> win == NULL)
    {
        mlx_destroy_display(fractal -> mlx);
        free(fractal -> mlx);
        malloc_error();
    }

    fractal -> img.img_ptr = mlx_new_image(fractal -> mlx, WIDTH, HEIGHT);
    if (fractal -> img.img_ptr == NULL)
    {
        mlx_destroy_window(fractal -> mlx, fractal -> win);
        mlx_destroy_display(fractal -> mlx);
        free(fractal -> mlx);
        malloc_error();
    }

    fractal -> img.pixel_ptr = mlx_get_data_addr(fractal -> img.img_ptr,
                                                    &fractal -> img.bits_per_pixel,
                                                    &fractal -> img.line_length,
                                                    &fractal -> img.endian);

    data_init(fractal);
    events_init(fractal);
}