/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:42:25 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/04 16:22:16 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_rgb
{
	double	red;
	double	green;
	double	blue;
}	t_rgb;

uint32_t	encode_color(t_rgb color);
t_rgb		set_color(t_rgb color);
t_rgb		color_add(t_rgb a, t_rgb b);
t_rgb		color_mult(t_rgb a, t_rgb b);
t_rgb		color_mult_scalar(t_rgb a, double b);

#endif
