/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 15:04:57 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Esta função é essencial para:

    Converter coordenadas de pixels da tela para coordenadas do plano complexo

    Mapear posições do mouse para cálculos matemáticos

    Ajustar escalas entre diferentes sistemas de coordenadas

A função implementa a transformação linear:
value_convertido=(novo_max - novo_min)*(valor_original) / (old_max) + novo_min

É uma função fundamental para trabalhar com visualização de
fractais e outros gráficos.
*/
double	map(double unscaled_num, double new_min, double new_max,
	double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / (old_max) + new_min);
}
