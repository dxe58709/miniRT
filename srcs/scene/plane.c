/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:29:31 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/14 22:31:26 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*set_plane(char *line)
{
	t_plane		*plane;
	char		**split;

	plane = (t_plane *)ft_calloc(1, sizeof(t_plane));
	if (!plane)
		print_err_exit(ERR_MALLOC);
	split = split_space(line);
	split_count(split, 4, ERR_PLANE_ARGC);
	if (ft_strcmp(split[0], "pl"))
		print_err_exit(ERR_OBJ_TYPE);
	plane->position = generate_xyz_vec(split[1]);
	plane->normal = check_vector_range(split[2], -1, 1);
	plane->rgb = process_rgb_str(split[3]);
	free_split(split);
	return (plane);
}