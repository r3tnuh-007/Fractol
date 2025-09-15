/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_key_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 13:31:17 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//I have to remove printf later
int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handle(fractal);
	else if (keysym == XK_Up && fractal -> shift_y > -3.5)
		fractal -> shift_y -= 0.4 * fractal -> zoom;
	else if (keysym == XK_Down && fractal -> shift_y < 3.5)
		fractal -> shift_y += 0.4 * fractal -> zoom;
	else if (keysym == XK_Right && fractal -> shift_x > -3.5)
		fractal -> shift_x -= 0.4 * fractal -> zoom;
	else if (keysym == XK_Left && fractal -> shift_x < 3.5)
		fractal -> shift_x += 0.4 * fractal -> zoom;
	else if (keysym == 61)
		fractal -> max_iterations += 10;
	else if (keysym == XK_minus)
		fractal -> max_iterations -= 10;
	else if (keysym == 114)
		data_init(fractal);
	fractal_render(fractal);
	return (0);
}
