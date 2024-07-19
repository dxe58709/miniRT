/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:51:32 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/19 23:15:11 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersection_plane(const t_scene *scene, const t_ray *ray,
	t_intersect *info)
{
	const t_plane	*plane;
	double			is_palallel;
	double			t;
	t_vec			s_p;

	plane = scene->type;
	is_palallel = inner_vec(plane->vertical, ray->direction);
	if (is_palallel == 0)
		return (false);
	s_p = diff_vec(plane->point, ray->start);
	t = (inner_vec(s_p, plane->vertical) / is_palallel);
	if (t > 0)
	{
		if (info)
		{
			info->distance = t;
			info->position = add_vec(ray->start, mult_vec(ray->direction, t));
			info->normal = plane->vertical;
		}
		return (true);
	}
	return (false);
}
