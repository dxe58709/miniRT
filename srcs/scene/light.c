/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:52:16 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 18:52:17 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	init_light(char *line)
{
	t_light		light;
	char		**split;

	split = split_space(line);
	split_count(split, 4, ERR_LIGHT_ARGC);
	if (ft_memcmp(split[0], "L", 2))
		print_err_exit(ERR_OBJ_TYPE);
	light.position = generate_xyz_vec(split[1]);
	light.ratio = check_atof_range(split[2], 0, 1);
	light.rgb = process_rgb_str(split[3]);
	free_split(split);
	return (light);
}
