/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:35:57 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 18:47:40 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	generate_xyz_vec(char *str)
{
	t_vec	vector;
	char	**split;

	split = ft_split(str, ',');
	if (split == NULL)
		print_err_exit(ERR_MALLOC);
	split_count(split, 3, "Invalid format of vector");
	vector.x = ft_atof(split[0]);
	vector.y = ft_atof(split[1]);
	vector.z = ft_atof(split[2]);
	free_split(split);
	return (vector);
}

t_vec	check_vector_range(char *str, double min, double max)
{
	t_vec	vector;

	vector = generate_xyz_vec(str);
	if (!is_in_range_double(vector.x, min, max)
		|| !is_in_range_double(vector.y, min, max)
		|| !is_in_range_double(vector.z, min, max))
		print_err_exit("Invalid range of vector");
	if (vector.x == 0 && vector.y == 0 && vector.z == 0)
		print_err_exit("Invalid vector");
	return (vector);
}
