/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_handle_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 03:20:13 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
1 - How many times i will iterate z²? -> while (i < fractal -> max_iterations)

2 - is the value escaped??
if hypotenuse > 2 I consider it escaped

3 - when the loop finish properly we are on the fractol
We are in the Mandelbrotset given the max iterations
*/
void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;
	double		tmp_real;

	z.real = 0;
	z.i = 0;
	i = 0;
	c.real = (map(x, -2, +2, WIDTH) * fractal -> zoom) + fractal -> shift_x;
	c.i = (map(y, +2, -2, HEIGHT) * fractal -> zoom) + fractal -> shift_y;
	while (i < fractal -> max_iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.i * z.i) > fractal -> escape_value)
		{
			color = map(i, BLACK, WHITE, fractal -> max_iterations);
			my_pixel_put(&fractal -> img, x, y, color);
			return ;
		}
		i ++;
	}
	my_pixel_put(&fractal -> img, x, y, BLACK);
}
