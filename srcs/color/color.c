/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:03:05 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/04 16:07:50 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

uint32_t	encode_color(t_rgb color)
{
	u_int8_t	red;
	u_int8_t	green;
	u_int8_t	blue;

	red = (u_int8_t)(color.red * 255);
	green = (u_int8_t)(color.green * 255);
	blue = (u_int8_t)(color.blue * 255);
	return ((red << 16) | (green << 8) | blue);
}