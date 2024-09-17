/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:11:24 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/17 15:03:38 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

void	set_clamp_color(t_rgb *color)
{
	color->red = clamp(color->red, 0.0, 1.0);
	color->green = clamp(color->green, 0.0, 1.0);
	color->blue = clamp(color->blue, 0.0, 1.0);
}

t_rgb	color_add(t_rgb *a, t_rgb b)
{
	t_rgb	result;

	result.red = a->red + b.red;
	result.green = a->green + b.green;
	result.blue = a->blue + b.blue;
	return (result);
}

t_rgb	color_mult(t_rgb *a, t_rgb b)
{
	t_rgb	result;

	result.red = a->red * b.red;
	result.green = a->green * b.green;
	result.blue = a->blue * b.blue;
	return (result);
}

void	color_mult_scalar(t_rgb *a, double b)
{
	a->red *= b;
	a->green *= b;
	a->blue *= b;
}
