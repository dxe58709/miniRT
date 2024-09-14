/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:46:35 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/15 00:31:06 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "vector.h"
typedef struct s_rgb {
	double	red;
	double	green;
	double	blue;
}	t_rgb;

typedef struct s_light {
	t_vec			position;
	double			ratio;
	t_rgb			rgb;
	struct s_light	*next;
}	t_light;

typedef struct s_ambient {
	double	ratio;
	t_rgb	rgb;
}	t_ambient;

typedef struct s_camera {
	t_vec	position;
	t_vec	direction;
	double	fov;
}	t_camera;

typedef struct s_ray {
	t_vec	position;
	t_vec	direction;
}	t_ray;

typedef struct s_ref {
	t_rgb	ambient_ref;//環境反射係数
	t_rgb	diffuse_ref;//拡散反射係数
	t_rgb	specular_ref;//鏡面反射係数
	double	gloss;//光尺度
}	t_ref;

typedef struct s_plane {
	t_vec	position;
	t_vec	normal;
	t_rgb	rgb;
}	t_plane;

typedef struct s_sphere {
	t_vec	position;
	double	radius;
	t_rgb	rgb;
}	t_sphere;

typedef struct s_cylinder {
	t_vec	position;
	t_vec	direction;
	double	radius;//円柱の半径
	double	height;
	t_rgb	rgb;
}	t_cylinder;

typedef enum e_shape_type {
	ST_SPHERE = 1,
	ST_PLANE,
	ST_CYLINDER,
}	t_shape_type;

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

typedef struct s_object {
	t_shape_type	type;
	union
	{
		t_plane		*plane;
		t_sphere	*sphere;
		t_cylinder	*cylinder;
	}	u_data;
	struct s_object	*next;
}	t_object;

typedef struct s_intersect {
	double		distance;
	t_vec		position;
	t_vec		normal;
	t_rgb		object_color;
}	t_intersect;

#endif