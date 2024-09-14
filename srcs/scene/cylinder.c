/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:27:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/14 22:31:08 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*set_cylinder(char *line)
{
	t_cylinder	*cylinder;
	char		**split;

	cylinder = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
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
