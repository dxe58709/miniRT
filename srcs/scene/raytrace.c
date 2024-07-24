/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:11:33 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 22:04:05 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	raytracing(t_scene *scene, t_ray *camera_pos, t_rgb *rgb)
{
	(void)scene;
	(void)camera_pos;
	(void)rgb;
	return (1);
}

// bool	raytrace(const t_scene *scene, \
// 					const t_ray *eye_ray, t_rgb *rgb)
// {
// 	t_rt	rt;

// 	set_info(&rt.info, INFINITY, false, true);
// 	if (get_nearest_shape(scene, eye_ray, rt.info, &rt.shape_intp))
// 	{
// 		calc_ambient_ref(rgb, scene, &rt);
// 		rt.light = scene->light;
// 		while (rt.light != NULL)
// 		{
// 			if (is_in_shadow(scene, &rt))
// 				continue ;
// 			calc_diffuse_ref(rgb, &rt);
// 			if (rt.vars.nl_dot > 0)
// 				calc_specular_ref(rgb, eye_ray, &rt);
// 			rt.light = rt.light->next;
// 		}
// 		clamp_mul_rgb(rgb, 255);
// 		return (true);
// 	}
// 	return (false);
// }