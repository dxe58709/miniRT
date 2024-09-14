/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:30:08 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/14 22:32:25 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*set_sphere(char *line)
{
	t_sphere	*sphere;
	char		**split;

	sphere = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
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
