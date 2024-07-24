/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:40:53 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 22:05:24 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersection_plane(const t_scene *scene, const t_ray *ray,
			t_intersect *info);
bool	intersection_sphere(const t_scene *scene, const t_ray *ray,
			t_intersect *info);
bool	intersection_cylinder(const t_scene *scene, const t_ray *ray,
			t_intersect *info);

bool	sphere_type(const t_scene *scene, const t_ray *ray, t_intersect *info)
{
	if (scene->object->type == ST_PLANE)
		return (intersection_plane(scene, ray, info));
	else if (scene->object->type == ST_SPHERE)
		return (intersection_sphere(scene, ray, info));
	else if (scene->object->type == ST_CYLINDER)
		return (intersection_cylinder(scene, ray, info));
	return (false);
}

// bool	get_nearest_shape(const t_scene *scene, const t_ray *ray, \
// 							t_info info, t_shape_intp *shape_intp)
// {
// 	t_shape		*nearest_shape;
// 	t_intersect	nearest_intp;
// 	t_intersect	intp;
// 	t_shape		*shape;

// 	nearest_shape = NULL;
// 	nearest_intp.distance = info.max_dist;
// 	shape = scene->shape;
// 	while (shape != NULL)
// 	{
// 		if (intersect(shape, ray, &intp) && \
// 			intp.distance < nearest_intp.distance)
// 		{
// 			nearest_shape = shape;
// 			nearest_intp = intp;
// 			if (info.exit_once_found)
// 				break ;
// 		}
// 		shape = shape->next;
// 	}
// 	if (set_output(nearest_shape, nearest_intp, info, shape_intp))
// 		return (true);
// 	return (false);
// }
