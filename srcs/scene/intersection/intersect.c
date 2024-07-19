/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:40:53 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/19 17:47:33 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	issphere(const char **argv, t_scene *scene)
{
	if (ft_strchr(argv[0][0], "A"))
		return (init_ambient_light());
	else if (ft_strchr(argv[0][0], "C"))
		return (init_camera(scene));
	else if (ft_strchr(argv[0][0], "L"))
		return (init_light(scene));
	else if (ft_strchr(argv[0][0], "pl"))
		return (init_plane(scene, argv));
	else if (ft_strchr(argv[0][0], "sp"))
		return (init_sphere(scene));
	else if (ft_strchr(argv[0][0], "cy"))
		return (init_cylinder(scene, argv));
	return (false);
}
