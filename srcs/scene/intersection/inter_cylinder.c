/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:14:41 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/20 00:15:46 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	squrt_discriminant(t_discrim *d);

static t_discrim	cy_discriminant(const t_ray *ray, const t_cylinder *cy)
{
	t_vec		s_p;
	t_discrim	d;

	s_p = diff_vec(ray->start, cy->position);
	d.a = inner_vec(ray->direction, ray->direction)
		- pow(inner_vec(cy->direction, ray->direction), 2);
	d.b = inner_vec(ray->direction, cy->direction)
		- inner_vec(ray->direction, cy->direction)
		* inner_vec(s_p, cy->direction);
	d.c = inner_vec(s_p, s_p) - pow(inner_vec(s_p, cy->direction), 2)
		- pow(cy->radius, 2);
	d.discrim = d.b * d.b - 4 * d.a * d.c;
	d.t = -1.0f;
	squrt_discriminant(&d);
	d.m = inner_vec(s_p, cy->direction)
		+ d.t * inner_vec(ray->direction, cy->direction);
	if (d.m < -cy->height / 2 || d.m > cy->height / 2)
		d.t = -1;
	return (d);
}

bool	intersection_cylinder(const t_scene *scene, const t_ray *ray,
	t_intersect *info)
{
	const t_cylinder	*cylinder;
	t_discrim			d;

	cylinder = scene->type;
	d = cy_discriminant(ray, cylinder);
	if (d.t > 0)
	{
		if (info)
		
		return (true);
	}
	return (false);
}
