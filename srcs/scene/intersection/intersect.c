/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:40:53 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/22 15:31:48 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// bool	issphere(const char **argv, t_scene *scene)
// {
// 	if (ft_strchr(argv[0][0], "A"))
// 		return (init_ambient_light());
// 	else if (ft_strchr(argv[0][0], "C"))
// 		return (init_camera(scene));
// 	else if (ft_strchr(argv[0][0], "L"))
// 		return (init_light(scene));
// 	else if (ft_strchr(argv[0][0], "pl"))
// 		return (init_plane(scene, argv));
// 	else if (ft_strchr(argv[0][0], "sp"))
// 		return (init_sphere(scene));
// 	else if (ft_strchr(argv[0][0], "cy"))
// 		return (init_cylinder(scene, argv));
// 	return (false);
// }

bool	sphere_type(const t_scene *scene, const t_ray *ray, t_intersect *info)
{
	if (scene->type == ST_PLANE)
		return (intersect_plane(scene, ray, info));
	else if (scene->type == ST_SPHERE)
		return (intersect_sphere(scene, ray, info));
	else if (scene->type == ST_CYLINDER)
		return (intersect_cylinder(scene, ray, info));
	return (false);
}

// bool	get_shape(const t_scene *scene, const t_ray *ray)
// {
// }