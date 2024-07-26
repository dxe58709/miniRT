/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:41:59 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/26 16:44:57 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*init_plane(char *line)
{
	t_plane		*plane;
	char		**split;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		print_err_exit(ERR_MALLOC);
	split = split_space(line);
	split_count(split, 4, ERR_PLANE_ARGC);
	if (ft_strcmp(split[0], "pl"))
		print_err_exit(ERR_OBJ_TYPE);
	plane->positioin = generate_xyz_vec(split[1]);
	plane->normal = check_vector_range(split[2], -1, 1);
	plane->rgb = process_rgb_str(split[3]);
	free_split(split);
	return (plane);
}
