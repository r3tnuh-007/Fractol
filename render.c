#include "fractol.h"

void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    double tmp_real;

    z.real = 0;
    z.i = 0;
    c.real = map(x, -2, +2, 0, WIDTH);
    c.i = map(y, +2, -2, 0, HEIGHT);

    //How many times i will iterate z²
    while (???)
    {
        z = sum_complex(square_complex(z), c);

        //is the value escaped??
        if (???)
        {
            my_pixel_put();
            return ;
        }
    }
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
}