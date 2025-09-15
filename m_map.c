/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 03:19:34 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, double new_max,
	double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / (old_max) + new_min);
}
