/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_square_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 01:31:16 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.i * z.i);
	result.i = 2 * z.real * z.i;
	return (result);
}
