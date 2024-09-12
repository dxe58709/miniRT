/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:01:38 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/12 17:01:31 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

#include "minirt.h"

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_light
{
	t_vec	position;
	double	ratio;
	int		rgb;
}	t_light;

typedef struct s_ambient
{
	double	ratio;
	int		rgb;
}	t_ambient;

typedef struct s_ray
{
	t_vec	start;
	t_vec	direction;
}	t_ray;

typedef struct s_plane
{
	t_vec	position;//平面上のある点の位置ベクトル
	t_vec	normal;//垂直ベクトル
	int		rgb;
}	t_plane;

typedef struct s_sphere
{
	t_vec	center;//球の中心
	double	radius;//半径
	int		rgb;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec	position;
	t_vec	direction;
	double	radius;//円柱の半径
	double	height;
	int		rgb;
}	t_cylinder;

typedef struct s_intersect {
	double	distance;
	t_vec	position;
	t_vec	normal;//法線ベクトル
}	t_intersect;

typedef struct s_ref {
	t_rgb	ambient_ref;//環境反射係数
	t_rgb	diffuse_ref;//拡散反射係数
	t_rgb	specular_ref;//鏡面反射係数
	double	gloss;//光尺度
}	t_ref;

typedef enum e_shape_type {
	ST_SPHERE = 1,
	ST_PLANE,
	ST_CYLINDER,
}	t_shape_type;

typedef struct s_camera {
	t_vec	camera_pos;
	t_vec	camera_dir;
	double	fov;//視野角（Field of View）
}	t_camera;

typedef struct s_discrim {
	double	a;
	double	b;
	double	c;
	double	discrim;
	double	m;
	double	t;
	double	t1;
	double	t2;
}	t_discrim;

//color
void	init_rgb(t_rgb *rgb, double r, double g, double b);
double	clamp(double value, double min, double max);
void	set_clamp_color(t_rgb color);
int		process_rgb_str(char *str);
#endif
