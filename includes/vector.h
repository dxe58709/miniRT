/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:43:36 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/27 18:34:31 by nsakanou         ###   ########.fr       */
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
