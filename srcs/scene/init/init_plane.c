/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:27:45 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 00:23:30 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_basis_plane(t_scene *scene, t_plane *plane)
{
	plane->basis.center = diff_vec(plane->positioin, scene->camera_pos);
	set_basis(&plane->basis);
}

bool	init_plane(t_scene *scene)
{
	scene->type = ST_PLANE;
	scene->plane = ft_calloc(1, sizeof(t_plane));
	if (!scene->plane)
		return (false);
	scene->plane->positioin = init_vec(0.0, 0.0, 0.0);
	scene->plane->normal = init_vec(0.0, 1.0, 0.0);
	scene->plane->rgb = init_rgb(255, 255, 255);
	set_basis_plane(scene, scene->plane);
	return (true);
}

bool	set_plane(t_scene *scene, char **params)
{
	// const size_t	data[5] = {1, 3, 3, 3, 1};
	const size_t	tp_len = 5;
	const size_t	dp_lens[5] = {1, 3, 3, 3, 1};
	t_shape			*shape;
	t_plane			*pl;
	t_rgb			rgb;

	if (!is_valid_format(splited, tp_len, dp_lens) \
		|| !append_shape(scene))
		return (false);
	shape = lst_last_shape(scene->shape);
	shape->type = ST_PLANE;
	pl = &shape->u_data.plane;
	if (!is_valid_vec(splited[1], &pl->position, false) \
		|| !is_valid_vec(splited[2], &pl->normal, true))
		return (false);
	if (!is_valid_rgb(splited[3], &rgb))
		return (false);
	if (!is_valid_double(splited[4][0], &shape->checker_board_w, 0.0, INFINITY))
		return (false);
	if (shape->checker_board_w != 0.0)
		set_basis_plane(pl, scene);
	shape->material.diffuse_ref = calc_rgb_ratio(rgb, 1.0);
	default_material(&shape->material);
	return (true);

	// if (!scene->plane || !params)
	// 	print_error(ERR_INVALID_PARAMS, false);
	return (true);
}


/*
 * params = ["coordinates", "normal", "rgb"]
 */
// int			set_plane(t_world *world, char **params)
// {
// 	t_object	*object;
// 	t_vec3		positioin;
// 	t_vec3		normal;
// 	t_fcolor	fcolor;

// 	if (ptrarr_len((void**)params) != 3 ||
// 		get_vec3_from_str(&positioin, params[0]) == ERROR ||
// 		get_vec3_from_str(&normal, params[1]) == ERROR ||
// 		get_fcolor_from_rgbstr(&fcolor, params[2]) == ERROR)
// 		return (put_and_return_err("Plane is Misconfigured"));
// 	if (!(object = plane_init(positioin, vec3_normalize(normal),
// 				material_init(fcolor,
// 								fcolor_init(0.3, 0.3, 0.3),
// 								SHININESS))) ||
// 		!(ft_lstadd_back_new(&world->objects, object)))
// 		return (put_and_return_err("failed malloc object"));
// 	return (0);
// }