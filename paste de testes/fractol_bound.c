/*
I have 2 kinds of fractals in mind:
the Mandelbrot set and the Julia set.

-> ./fractol mandelbrot
-> ./fractol julia

*/
#include <stdio.h>

typedef struct s_complex
{
    double real;
    double i;
} t_complex;

int main(void)
{
    t_complex z, c;
    double tmp_real;

    z.real = 0;
    z.i = 0;

    c.real = 0.25;
    c.i = 0.4;

    // z = z² + c
    for (int i = 0; i < 100000; i ++)
    {
        tmp_real = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.real * z.i;
        z.real = tmp_real;
        z.real += c.real;
        z.i += c.i;

        printf("\nIteration n -> %d real: %f   imaginary: %f\n", i, z.real, z.i);
    }
    return (0);
}