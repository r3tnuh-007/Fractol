/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:23:03 by aluis             #+#    #+#             */
/*   Updated: 2025/09/15 15:31:56 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	m_atoi(char *s)
{
	long	int_part;
	double	frac_part;
	double	pow;
	int		sign;

	int_part = 0;
	frac_part = 0.0;
	sign = +1;
	pow = 1.0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign *= -1;
	while (*s >= '0' && *s <= '9' && (*s != '.') && *s)
		int_part = int_part * 10 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9' && *s)
	{
		pow /= 10;
		frac_part += (*s++ - '0') * pow;
	}
	return ((int_part + frac_part) * sign);
}
