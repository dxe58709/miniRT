/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:46:46 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/24 00:05:40 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	init_vector(double x, double y, double z)
{
	t_vec	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

//|a|
double	abs_vec(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

//各成分の二乗和
double	square_sum(t_vec a)
{
	return (inner_vec(a, a));
}

//ベクトル a を長さを1にする
t_vec	normalize_vec(t_vec a)
{
	double	abs;

	abs = abs_vec(a);
	return (init_vector(a.x / abs, a.y / abs, a.z / abs));
}
