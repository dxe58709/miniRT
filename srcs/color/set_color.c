/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:41:18 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/15 10:35:52 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

void	set_clamp_color(t_rgb color)
{
	color.red = clamp(color.red, 0.0, 1.0);
	color.green = clamp(color.green, 0.0, 1.0);
	color.blue = clamp(color.blue, 0.0, 1.0);
}

void	color_add(t_rgb a, t_rgb b)
{
	a.red += b.red;
	a.green += b.green;
	a.blue += b.blue;
}

void	color_mult(t_rgb a, t_rgb b)
{
	a.red *= b.red;
	a.green *= b.green;
	a.blue *= b.blue;
}

void	color_mult_scalar(t_rgb a, double b)
{
	a.red *= b;
	a.green *= b;
	a.blue *= b;
}
