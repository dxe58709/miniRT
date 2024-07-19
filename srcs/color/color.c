/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:03:05 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/19 15:31:49 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_rgb(t_rgb *rgb, double r, double g, double b)
{
	rgb->red = r;
	rgb->green = g;
	rgb->blue = b;
}

int	encode_color(t_rgb color)
{
	int	red;
	int	green;
	int	blue;

	red = (int)(color.red * 255);
	green = (int)(color.green * 255);
	blue = (int)(color.blue * 255);
	return ((red << 16) | (green << 8) | blue);
}
