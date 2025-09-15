/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_fractal_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 03:12:29 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y ++ < HEIGHT)
	{
		x = 0;
		while (x ++ < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal -> mlx, fractal -> win,
		fractal -> img.img_ptr, 0, 0);
}
