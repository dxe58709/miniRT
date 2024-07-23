/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:48:45 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/23 22:50:46 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_sphere(t_scene *scene)
{
	scene->type == ST_SPHERE;
	scene->sphere = malloc(sizeof(t_sphere));
	if (!scene->sphere)
		return (false);
	return (true);
}
