/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:06:31 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/15 12:05:23 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersection_plane(const t_object *object, const t_ray *ray,
			t_intersect *info);
bool	intersection_sphere(const t_object *object, const t_ray *ray,
			t_intersect *info);
bool	intersection_cylinder(const t_object *object, const t_ray *ray,
			t_intersect *info);

static bool	found_intersection(const t_object *object, const t_ray *ray,
t_intersect *info)
{
	if (object->type == ST_PLANE)
		return (intersection_plane(object, ray, info));
	else if (object->type == ST_SPHERE)
		return (intersection_sphere(object, ray, info));
	else if (object->type == ST_CYLINDER)
		return (intersection_cylinder(object, ray, info));
	return (false);
}

static bool	update_nearest_info(const t_ray *ray, const t_object *object,
t_intersect *info)
{
	t_intersect	temp_info;
	bool		found;

	found = found_intersection(object, ray, &temp_info);
	if (found && temp_info.distance < info->distance)
	{
		info->distance = temp_info.distance;
		info->position = temp_info.position;
		info->normal = temp_info.normal;
		if (object->type == ST_PLANE)
			info->object_color = object->u_data.plane->rgb;
		else if (object->type == ST_SPHERE)
			info->object_color = object->u_data.sphere->rgb;
		else if (object->type == ST_CYLINDER)
			info->object_color = object->u_data.cylinder->rgb;
		return (true);
	}
	return (false);
}

static void	init_intersect_info(t_intersect *info)
{
	info->distance = INFINITY;
	info->position = (t_vec){0, 0, 0};
	info->normal = (t_vec){0, 0, 0};
}

bool	get_nearest_shape(const t_scene *scene, const t_ray *ray,
t_intersect *info)
{
	const t_object	*current;
	bool			found;

	found = false;
	init_intersect_info(info);
	current = scene->object;
	while (current)
	{
		if (update_nearest_info(ray, current, info))
			found = true;
		current = current->next;
	}
	return (found);
}
