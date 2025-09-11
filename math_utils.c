#include "fractol.h"

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex result;

    result.real = z1.real + z2.real;
    result.i = z1.i + z2.i;
    return (result);
}

t_complex square_complex(t_complex z)
{
    t_complex result;

    result.real = (z.real * z.real) - (z.i * z.i);
    result.i = 2 * z.real * z.i;
    return (result);
}