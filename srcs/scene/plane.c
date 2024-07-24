/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:41:59 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 16:04:15 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*plane(char *line)
{
	t_plane		*plane;
	char		**split;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		print_err_exit(ERR_MALLOC);
	split = split_space(line);
	split_count(split, 4, ERR_PLANE_ARGC);
	if (ft_memcmp(split[0], "pl", 3))
		print_err_exit(ERR_OBJ_TYPE);
	plane->positioin = atof_vector_position(split[1]);
	plane->normal = check_vector_range(split[2], -1, 1);
	plane->rgb = check_atof_rgb(split[3]);
	free_split(split);
	return (plane);
}
