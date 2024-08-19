/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:29:09 by nsakanou          #+#    #+#             */
/*   Updated: 2024/08/09 17:08:00 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	init_camera(char *line)
{
	t_camera	camera;
	char		**split;

	split = split_space(line);
	split_count(split, 4, ERR_CAMERA_ARGC);
	if (ft_memcmp(split[0], "C", 2))
		print_err_exit(ERR_OBJ_TYPE);
	    // デバッグ用出力
    printf("Camera Initialization:\n");
    printf("Camera Position Input: %s\n", split[1]);
    printf("Camera Direction Input: %s\n", split[2]);
    printf("Camera FOV Input: %s\n", split[3]);
	camera.camera_pos = generate_xyz_vec(split[1]);
	camera.camera_dir = check_vector_range(split[2], -1, 1);
	camera.fov = check_atof_range(split[3], 0, 180);
	    // デバッグ用出力
    printf("Camera Position: (%f, %f, %f)\n", camera.camera_pos.x, camera.camera_pos.y, camera.camera_pos.z);
    printf("Camera Direction: (%f, %f, %f)\n", camera.camera_dir.x, camera.camera_dir.y, camera.camera_dir.z);
    printf("Camera FOV: %f\n", camera.fov);
	free_split(split);
	return (camera);
}
