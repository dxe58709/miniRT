/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:15:06 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 16:20:31 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*cylinder(char *line)
{
	t_cylinder	*cylinder;
	char		**split;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		print_err_exit(ERR_MALLOC);
	split = split_space(line);
	split_count(split, 6, ERR_CYLINDER_ARGC);
	if (ft_memcmp(split[0], "cy", 3))
		print_err_exit(ERR_OBJ_TYPE);
	cylinder->position = atof_vector_position(split[1]);
	cylinder->direction = check_vector_range(split[2], -1, 1);
	cylinder->radius = ft_atof(split[3]);
	cylinder->height = ft_atof(split[4]);
	cylinder->rgb = check_atof_rgb(split[3]);
	free_split(split);
	return (cylinder);
}
