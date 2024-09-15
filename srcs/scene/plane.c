/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:29:31 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/15 18:10:35 by nsakanou         ###   ########.fr       */
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

bool	intersection_plane(const t_object *object, const t_ray *ray,
	t_intersect *info)
{
	const t_plane	*plane;
	double			is_palallel;
	double			t;
	t_vec			s_p;

	plane = object->u_data.plane;
	s_p = diff_vec(plane->position, ray->position);
	is_palallel = inner_vec(plane->normal, ray->direction);
	if (fabs(is_palallel) < 1e-6)
		return (false);
	t = -1.0 * (inner_vec(s_p, plane->normal) / is_palallel);
	if (t > 0)
	{
		if (info)
		{
			info->distance = t;
			info->position = add_vec(ray->position,
					mult_vec(ray->direction, t));
			info->normal = plane->normal;
		}
		return (true);
	}
	return (false);
}
