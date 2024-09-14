/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:37:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/14 21:38:12 by nsakanou         ###   ########.fr       */
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

typedef struct s_basis //座標系の回転や変換に関する情報
{
	t_vec	center;//座標系の中心点
	t_vec	up;//座標系の上方向
	t_vec	vertical;//座標系の垂直方向
}	t_basis;

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


t_vec	generate_xyz_vec(char *str);
t_vec	check_vector_range(char *str, double min, double max);

//basis
void	set_basis(t_basis *basis);
#endif