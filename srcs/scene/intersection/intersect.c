/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:40:53 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/23 22:09:17 by nsakanou         ###   ########.fr       */
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
	if (scene->type == ST_PLANE)
		return (intersection_plane(scene, ray, info));
	else if (scene->type == ST_SPHERE)
		return (intersection_sphere(scene, ray, info));
	else if (scene->type == ST_CYLINDER)
		return (intersection_cylinder(scene, ray, info));
	return (false);
}

// bool	get_shape(const t_scene *scene, const t_ray *ray)
// {
// }