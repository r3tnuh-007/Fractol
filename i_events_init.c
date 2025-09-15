/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_events_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 13:49:54 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal -> win, KeyPress, KeyPressMask, key_handle, fractal);
	mlx_hook(fractal -> win, ButtonPress, ButtonPressMask, mouse_handle, fractal);
	mlx_hook(fractal -> win, DestroyNotify, StructureNotifyMask, close_handle, fractal);
}
