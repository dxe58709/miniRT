/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:30:08 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/14 23:01:52 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*set_sphere(char *line)
{
	t_sphere	*sphere;
	char		**split;

	sphere = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		print_err_exit(ERR_MALLOC);
	split = split_space(line);
	split_count(split, 4, ERR_SPHERE_ARGC);
	if (ft_strcmp(split[0], "sp"))
		print_err_exit(ERR_OBJ_TYPE);
	sphere->position = generate_xyz_vec(split[1]);
	sphere->radius = ft_atof(split[2]);
	sphere->rgb = process_rgb_str(split[3]);
	free_split(split);
	return (sphere);
}

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

	s_c = diff_vec(ray->position, sphere->position);
	d.a = inner_vec(ray->direction, ray->direction);
	d.b = 2 * inner_vec(s_c, ray->direction);
	d.c = inner_vec(s_c, s_c) - sphere->radius * sphere->radius;
	d.discrim = d.b * d.b - 4 * d.a * d.c;
	squrt_discriminant(&d);
	return (d);
}

bool	intersection_sphere(const t_object *object, const t_ray *ray,
						t_intersect *info)
{
	const t_sphere	*sphere;
	t_discrim		d;

	if (object->type != ST_SPHERE)
		return (false);
	sphere = object->u_data.sphere;
	d = sp_discriminant(ray, sphere);
	if (d.discrim < 0)
		return (false);
	if (d.t > 0)
	{
		if (info)
		{
			info->distance = d.t;
			info->position = add_vec(ray->position,
					mult_vec(ray->direction, d.t));
			info->normal = diff_vec(info->position, sphere->position);
			info->normal = normalize_vec(info->normal);
		}
		return (true);
	}
	return (false);
}
