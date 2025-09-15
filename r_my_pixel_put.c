/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_my_pixel_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 02:24:03 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (img -> line_length * y) + (x * (img -> bits_per_pixel / 8));
	*((unsigned int *)(offset + img -> pixel_ptr)) = color;
}
