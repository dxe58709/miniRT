/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:04:51 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/26 16:45:03 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
