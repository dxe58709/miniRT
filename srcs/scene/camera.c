/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:29:09 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 16:42:15 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	camera(char *line)
{
	t_camera	camera;
	char		**split;

	split = split_space(line);
	split_count(split, 4, ERR_CAMERA_ARGC);
	if (ft_memcmp(split[0], "C", 2))
		print_err_exit(ERR_OBJ_TYPE);
	camera.camera_pos = atof_vector_position(split[1]);
	camera.camera_dir = check_vector_range(split[2], -1, 1);
	camera.fov = check_atof_range(split[3], 0, 180);
	free_split(split);
	return (camera);
}
