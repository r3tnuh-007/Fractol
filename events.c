#include "fractol.h"

int	close_handle(t_fractal *fractal)
{
    mlx_destroy_image(fractal -> mlx, fractal -> img.img_ptr);
    mlx_destroy_window(fractal -> mlx, fractal -> win);
    mlx_destroy_display(fractal -> mlx);
    free(fractal -> mlx);
    exit (0);
}

int key_handle (int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        close_handle(fractal);
    else if (keysym == XK_Up && fractal -> shift_y > -3.5)
        fractal -> shift_y -= 0.4 * fractal -> zoom;
    else if (keysym == XK_Down && fractal -> shift_y < 3.5)
        fractal -> shift_y += 0.4 * fractal -> zoom;
    else if (keysym == XK_Right && fractal -> shift_x > -3.5)
        fractal -> shift_x -= 0.4 * fractal -> zoom;
    else if (keysym == XK_Left && fractal -> shift_x < 3.5)
        fractal -> shift_x += 0.4 * fractal -> zoom;
    else if (keysym == 61)
        fractal -> max_iterations += 10;
    else if (keysym == XK_minus)
        fractal -> max_iterations -= 10;
    else if (keysym == 114)
        data_init(fractal);
    printf("%d\n", keysym);

    // Refresh the image
    fractal_render(fractal);
    return (0);
}

int mouse_handle(int button, int x, int y, t_fractal *fractal)
{
    if (button == 5)
        fractal -> shift_y -= 0.4 * fractal -> zoom;
    else if (button == 4)
        fractal -> shift_y += 0.4 * fractal -> zoom;
    else if (button == 6)
        fractal -> shift_x -= 0.4 * fractal -> zoom;
    else if (button == 7)
        fractal -> shift_x += 0.4 * fractal -> zoom;
    else if ((int) button == 65451 || button == 1)
        fractal -> zoom *= 0.95;
    else if ((int) button == 65453 || button == 3)
        fractal -> zoom *= 1.5;
    printf("%d\n", button);
    fractal_render(fractal);
    return (0);
}
