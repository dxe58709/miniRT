/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:03:05 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/03 17:40:18 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

uint32_t	color_2hex(t_rgb color)
{
	u_int8_t	red;
	u_int8_t	green;
	u_int8_t	blue;

	red = (u_int8_t)(color.red * 255);
	green = (u_int8_t)(color.green * 255);
	blue = (u_int8_t)(color.blue * 255);
	return ((red << 16) | (green << 8) | blue);
}

double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

t_rgb	color_init(double red, double green, double blue)
{
	t_rgb	color;

	color.red = clamp(red, 0.0, 1.0);
	color.green = clamp(green, 0.0, 1.0);
	color.blue = clamp(blue, 0.0, 1.0);
	return (color);
}

