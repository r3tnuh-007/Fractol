/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_fractal_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 13:55:28 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal -> mlx = mlx_init();
	if (fractal -> mlx == NULL)
		malloc_error();
	fractal -> win = mlx_new_window(fractal -> mlx, WIDTH,
			HEIGHT, fractal -> name);
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
			&fractal -> img.bits_per_pixel, &fractal -> img.line_length,
			&fractal -> img.endian);
	data_init(fractal);
	events_init(fractal);
}
