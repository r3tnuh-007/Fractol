#include "fractol.h"

void my_pixel_put(t_image *img, int x, int y, int color)
{
    int offset;

    offset = (img -> line_length * y) + (x * (img -> bits_per_pixel / 8));
    *((unsigned int *)(offset + img -> pixel_ptr)) = color;
    //printf("\n O offset é: %d\n O ponteiro eh: %u", offset, img -> pixel_ptr);
}

static void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int color;
    int i;
    double tmp_real;

    z.real = 0;
    z.i = 0;
    i = 0;
    c.real = (map(x, -2, +2, 0, WIDTH) * fractal -> zoom) + fractal -> shift_x;
    c.i = (map(y, +2, -2, 0, HEIGHT) * fractal -> zoom) + fractal -> shift_y;

    //How many times i will iterate z²
    while (i < fractal -> max_iterations)
    {
        z = sum_complex(square_complex(z), c);

        //is the value escaped??
        //if hypotenuse > 2 I consider it escaped
        if ((z.real * z.real) + (z.i * z.i) > fractal -> escape_value)
        {
            //color pixel
            color = map(i, BLACK, WHITE, 0, fractal -> max_iterations);
            /*
            if (i > 22)
                color = 0x808080;
            else
                color = BLACK;
            */
            my_pixel_put(&fractal -> img, x, y, color);
            return ;
        }
        i ++;
    }
    // We are in the Mandelbrotset given the max iterations
    my_pixel_put(&fractal -> img, x, y, BLACK);
}

void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while (y ++ < HEIGHT)
    {
        x = 0;
        while (x ++ < WIDTH)
        {
            handle_pixel(x, y, fractal);
        }
        
    }
    mlx_put_image_to_window(fractal -> mlx, fractal -> win, fractal -> img.img_ptr, 0, 0);
}