/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_mandel_vs_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 15:54:05 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal -> name, "mandelbrotset", 16))
	{
		c -> real = z -> real;
		c -> i = z -> i;
	}
	else if (!ft_strncmp(fractal -> name, "julia", 10))
	{
		c -> real = fractal -> julia_real;
		c -> i = fractal -> julia_imag;
	}
}
