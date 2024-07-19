/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:42:25 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/19 15:32:45 by nsakanou         ###   ########.fr       */
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

void	init_rgb(t_rgb *rgb, double r, double g, double b);
int		encode_color(t_rgb color);
void	set_clamp_color(t_rgb color);
void	color_add(t_rgb a, t_rgb b);
void	color_mult(t_rgb a, t_rgb b);
void	color_mult_scalar(t_rgb a, double b);

#endif
