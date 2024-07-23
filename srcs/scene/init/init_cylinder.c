/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:49:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/23 22:51:35 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_cylinder(t_scene *scene)
{
	scene->type == ST_CYLINDER;
	scene->cylinder = malloc(sizeof(t_cylinder));
	if (!scene->cylinder)
		return (false);
	return (true);
}
