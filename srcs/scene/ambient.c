/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:54:58 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 18:52:03 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient	init_ambient(char *line)
{
	t_ambient	ambient;
	char		**split;

	split = split_space(line);
	split_count(split, 3, ERR_AMBIENT_ARGC);
	if (ft_memcmp(split[0], "A", 2))
		print_err_exit(ERR_OBJ_TYPE);
	ambient.ratio = check_atof_range(split[1], 0, 1);
	ambient.rgb = process_rgb_str(split[2]);
	free_split(split);
	return (ambient);
}
