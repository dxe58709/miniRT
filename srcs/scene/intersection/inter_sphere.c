/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:30:09 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/23 21:08:41 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	squrt_discriminant(t_discrim *d)
{
	double		squrt_discrim;

	squrt_discrim = sqrt(d->discrim);
	d->t1 = (-d->b - squrt_discrim) / (2 * d->a);
	d->t2 = (-d->b + squrt_discrim) / (2 * d->a);
	if (d->t1 > 0)
		d->t = d->t1;
	if (d->t2 > 0 && d->t2 < d->t)
		d->t = d->t2;
}

static t_discrim	sp_discriminant(const t_ray *ray, const t_sphere *sphere)
{
	t_vec		s_c;
	t_discrim	d;

	s_c = diff_vec(ray->start, sphere->center);
	d.a = inner_vec(ray->direction, ray->direction);
	d.b = 2 * inner_vec(s_c, ray->direction);
	d.c = inner_vec(s_c, s_c) - sphere->radius * sphere->radius;
	d.discrim = d.b * d.b - 4 * d.a * d.c;
	squrt_discriminant(&d);
	return (d);
}

bool	intersection_sphere(const t_scene *scene, const t_ray *ray,
	t_intersect *info)
{
	const t_sphere	*sphere;
	t_discrim		d;

	if (scene->type != ST_SPHERE)
		return (false);
	sphere = scene->sphere;
	d = sp_discriminant(ray, sphere);
	if (d.discrim < 0)
		return (false);
	if (d.t > 0)
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
