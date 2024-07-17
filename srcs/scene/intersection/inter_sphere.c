/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:30:09 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/17 19:40:15 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_discrim	discriminant(const t_ray *ray, const t_sphere *sphere)
{
	t_vec		s_c;
	t_discrim	d;

	s_c = diff_vec(ray->start, sphere->center);
	d.a = inner_vec(ray->direction, ray->direction);
	d.b = 2 * inner_vec(s_c, ray->direction);
	d.c = inner_vec(s_c, s_c) - sphere->radius * sphere->radius;
	d.discrim = d.b * d.b - 4 * d.a * d.c;
	return (d);
}

static t_discrim	squrt_discriminant(const t_ray *ray, const t_sphere *sphere)
{
	double		squrt_discrim;
	t_discrim	d;

	squrt_discrim = sqrt(d.discrim);
	d.t1 = (-d.b - squrt_discrim) / (2 * d.a);
	d.t2 = (-d.b + squrt_discrim) / (2 * d.a);
	if (d.t1 < 0)
		d.t = -d.t1;
	else
		d.t = d.t1;
	return (d);
}

bool	intersection_sphre(const t_scene *scene, const t_ray *ray,
	t_intersect *info)
{
	const t_sphere	*sphere;
	t_discrim		d;

	sphere = scene->type;
	d = discriminant(ray, sphere);
	if (d.discrim < 0)
		return (false);
	d = squrt_discriminant(ray, sphere);
	if (d.t1 > 0 || d.t2 > 0)
	{
		if (info)
		{
			info->distance = d.t;
			info->position = add_vec(ray->start, mult_vec(ray->direction, d.t));
			info->normal = diff_vec(info->position, sphere->center);
			info->normal = normalize_vec(info->normal);
		}
		return (true);
	}
	return (false);
}
