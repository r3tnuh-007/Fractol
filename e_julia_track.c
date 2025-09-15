/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_julia_track.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 16:16:33 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal -> name, "julia", 10))
	{
		fractal -> julia_real = (map(x, -2, +2, WIDTH) * fractal -> zoom)
			+ fractal -> shift_x;
		fractal -> julia_imag = (map(y, +2, -2, HEIGHT) * fractal -> zoom)
			+ fractal -> shift_y;
		fractal_render(fractal);
	}
	return (0);
}
