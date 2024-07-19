/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:01:38 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/19 15:11:01 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

#include "minirt.h"

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

typedef struct s_plane
{
	t_vec	point;//平面上のある点の位置ベクトル
	t_vec	vertical;//垂直ベクトル
	t_basis	basis;//平面の基底
}	t_plane;

// typedef struct s_cone
// {
// 	t_vec	position;
// 	t_vec	vertical;
// 	double	radius;//円錐の半径
// 	double	height;
// }	t_cone;

typedef struct s_intersect {
	double	distance;
	t_vec	position;
	t_vec	normal;//法線ベクトル
}	t_intersect;

typedef struct s_material {
	t_rgb	ambient_ref;//環境反射係数
	t_rgb	diffuse_ref;//拡散反射係数
	t_rgb	specular_ref;//鏡面反射係数
	double	gloss;//光尺度
}	t_material;

typedef enum e_shape_type {
	ST_SPHERE,
	ST_PLANE,
	ST_CYLINDER,
	ST_CONE,
}	t_shape_type;

typedef struct s_scene {
	t_shape_type	type;
	t_light			*light;
	t_rgb			*ambients;
	t_basis			basis;
	t_vec			camera_pos;
	t_vec			camera_dir;
	double			fov;//視野角（Field of View）
}	t_scene;

typedef struct s_discrim {
	double	a;
	double	b;
	double	c;
	double	discrim;
	double	t;
	double	t1;
	double	t2;
}	t_discrim;

#endif
