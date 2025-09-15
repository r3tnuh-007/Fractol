/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_close_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 13:17:54 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal -> mlx, fractal -> img.img_ptr);
	mlx_destroy_window(fractal -> mlx, fractal -> win);
	mlx_destroy_display(fractal -> mlx);
	free(fractal -> mlx);
	exit (0);
}
