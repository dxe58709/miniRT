/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:43:36 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/03 14:20:51 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_ray
{
	t_vec	start;
	t_vec	direction;//方向ベクトル
}	t_ray;

typedef struct s_coordinate //座標系の回転や変換に関する情報
{
	t_vec	center;//座標系の中心点
	t_vec	up;//座標系の上方向
	t_vec	vertical;//座標系の垂直方向
}	t_coordinate;

typedef struct s_intersect {
	double	distance;
	t_vec	position;
	t_vec	normal;
}	t_intersect;

//vector
t_vec	init_vector(double x, double y, double z);
double	abs_vec(t_vec a);
double	square_sum(t_vec a);
t_vec	normalize_vec(t_vec a);

//arithmetics
t_vec	add_vec(t_vec a, t_vec b);
t_vec	diff_vec(t_vec a, t_vec b);
double	inner_vec(t_vec a, t_vec b);
t_vec	outer_vec(t_vec a, t_vec b);
t_vec	mult_vec(t_vec a, double b);

//set_vec
int		set_vec(t_vec *vec, char *str);

#endif
