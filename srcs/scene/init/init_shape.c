/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:41:59 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/10 19:05:28 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*init_plane(char *line)
{
	t_plane		*plane;
	char		**split;

	plane = (t_plane *)malloc(sizeof(t_plane));
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

t_sphere	*init_sphere(char *line)
{
	t_sphere	*sphere;
	char		**split;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		print_err_exit(ERR_MALLOC);
	split = split_space(line);
	split_count(split, 4, ERR_SPHERE_ARGC);
	if (ft_strcmp(split[0], "sp"))
		print_err_exit(ERR_OBJ_TYPE);
	sphere->center = generate_xyz_vec(split[1]);
	sphere->radius = ft_atof(split[2]);
	sphere->rgb = process_rgb_str(split[3]);
	free_split(split);
	return (sphere);
}

t_cylinder	*init_cylinder(char *line)
{
	t_cylinder	*cylinder;
	char		**split;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		print_err_exit(ERR_MALLOC);
	split = split_space(line);
	split_count(split, 6, ERR_CYLINDER_ARGC);
	if (ft_strcmp(split[0], "cy"))
		print_err_exit(ERR_OBJ_TYPE);
	cylinder->position = generate_xyz_vec(split[1]);
	cylinder->direction = check_vector_range(split[2], -1, 1);
	cylinder->radius = ft_atof(split[3]);
	cylinder->height = ft_atof(split[4]);
	cylinder->rgb = process_rgb_str(split[3]);
	free_split(split);
	return (cylinder);
}
