/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_mouse_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 13:33:40 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//I have to remove printf later
int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5)
		fractal -> shift_y -= 0.4 * fractal -> zoom;
	else if (button == 4)
		fractal -> shift_y += 0.4 * fractal -> zoom;
	else if (button == 6)
		fractal -> shift_x -= 0.4 * fractal -> zoom;
	else if (button == 7)
		fractal -> shift_x += 0.4 * fractal -> zoom;
	else if ((int) button == 65451 || button == 1)
		fractal -> zoom *= 0.95;
	else if ((int) button == 65453 || button == 3)
		fractal -> zoom *= 1.5;
	printf("%d\n", button);
	fractal_render(fractal);
	return (0);
}
