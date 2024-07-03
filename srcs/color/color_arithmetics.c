/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_arithmetics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:41:18 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/03 17:58:08 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_rgb	color_add(t_rgb a, t_rgb b)
{
	return (color_init(a.red + b.red, a.green + b.green, a.blue + b.blue));
}

t_rgb	color_mult(t_rgb a, t_rgb b)
{
	return (color_init(a.red * b.red, a.green * b.green, a.blue * b.blue));
}

t_rgb	color_mult_scalar(t_rgb a, double b)
{
	return (color_init(a.red * b, a.green * b, a.blue * b));
}
