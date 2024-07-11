/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:49:25 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/11 19:16:33 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	free_scene(t_scene *scene)
// {
// 	t_shape	*tmp_shape;
// 	t_light	*tmp_light;

// 	if (scene == NULL)
// 		return ;
// 	while (scene->shape != NULL)
// 	{
// 		tmp_shape = scene->shape->next;
// 		free(scene->shape);
// 		scene->shape = tmp_shape;
// 	}
// 	while (scene->light != NULL)
// 	{
// 		tmp_light = scene->light->next;
// 		free(scene->light);
// 		scene->light = tmp_light;
// 	}
// 	free(scene);
// }
