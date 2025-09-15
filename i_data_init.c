/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_data_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 13:46:33 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 // 2², my hypotenuse limit to consider a value escaped
 //value tight with image quality and rendering speed
*/
void	data_init(t_fractal *fractal)
{
	fractal -> escape_value = 8.0;
	fractal -> max_iterations = 42;
	fractal -> shift_x = 0.0;
	fractal -> shift_y = 0.0;
	fractal -> zoom = 1.0;
}
