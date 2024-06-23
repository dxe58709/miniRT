/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:35:21 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/24 00:13:19 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../srcs/libft/libft.h"
# include "vector.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>
# include <libc.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <ctype.h>
# include <stdbool.h>
# include <float.h>
# include <math.h>

# define WINDOW_WIDTH 400
# define WINDOW_HEIGHT 400

# define ERR_ARGC	"wrong argc."

//color
typedef struct s_rgb
{
	double	red;
	double	green;
	double	blue;
}	t_rgb;

typedef struct s_ray
{
    t_vec	start;
    t_vec	direction;//方向ベクトル
}	t_ray;

typedef struct s_basis
{
	t_vec	c;
	t_vec	u;
	t_vec	v;
}	t_basis;

typedef struct s_plane
{
    t_vec	vertical;//垂直ベクトル
    t_vec	position;//平面上のある点の位置ベクトル
    t_basis	basis;//平面の基底
}	t_plane;

typedef struct s_sphere
{
    t_vec	center;//球の中心
    double	radius;//半径
}	t_sphere;

typedef struct s_cylinder
{
    t_vec	position;
    t_vec	direction;
    double	radius;//円柱の半径
    double	height;
}	t_cylinder;

#endif