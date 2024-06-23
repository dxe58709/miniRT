/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:00:39 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/24 00:18:39 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	add_vec(t_vec a, t_vec b)
{
	return (init_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec	diff_vec(t_vec a, t_vec b)
{
	return (init_vector(a.x - b.x, a.y - b.y, a.z - b.z));
}

double	inner_vec(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	outer_vec(t_vec a, t_vec b)
{
	return (init_vector(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
}

t_vec	mult_vec(t_vec a, double b)
{
	return (init_vector(a.x * b, a.y * b, a.z * b));
}
