/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:29:09 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/05 17:00:56 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//(u, v) pixel座標
//アスペクト比に応じて幅、高さが計算される
t_ray	get_camera_ray(const t_scene *scene, double u,
							double v, double aspect)
{
	double	viewport_height;
	double	viewport_width;
	t_vec	horizon;
	t_vec	vertical;
	t_vec	ray_direction;

	viewport_height = 2.0 * tan(scene->fov / 2.0);
	viewport_width = aspect * viewport_height;
	horizon = mult_vec(scene->basis.vertical, viewport_width);
	vertical = mult_vec(scene->basis.up, viewport_height);
	ray_direction = normalize_vec(add_vec(add_vec(scene->camera_dir,
					mult_vec(horizon, u)), mult_vec(vertical, v)));
	return ((t_ray){scene->camera_pos, ray_direction});
}
