/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:27:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/17 23:34:29 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*set_cylinder(char *line)
{
	t_cylinder	*cylinder;
	char		**split;

	cylinder = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		print_err_exit(ERR_MALLOC);
	split = split_space(line);
	split_count(split, 6, ERR_CYLINDER_ARGC);
	if (ft_strcmp(split[0], "cy"))
		print_err_exit(ERR_OBJ_TYPE);
	cylinder->position = generate_xyz_vec(split[1]);
	cylinder->direction = check_vector_range(split[2], -1, 1);
	cylinder->radius = ft_atof(split[3]);
	cylinder->height = ft_atof(split[4]);
	cylinder->rgb = process_rgb_str(split[5]);
	free_split(split);
	return (cylinder);
}

void	cy_squrt_discriminant(t_discrim *d)
{
	double	squrt_discrim;

	squrt_discrim = sqrt(d->discrim);
	d->t1 = (-d->b - squrt_discrim) / (2 * d->a);
	d->t2 = (-d->b + squrt_discrim) / (2 * d->a);
	d->t = -1.0f;
	if (d->t1 > 0 && (d->t < 0 || d->t1 < d->t))//内側だったら＋
		d->t = d->t1;
	if (d->t2 > 0 && (d->t < 0 || d->t2 < d->t))//外側だったらー
		d->t = d->t2;
}

static t_discrim	cy_discriminant(const t_ray *ray, const t_cylinder *cy)
{
	// t_vec		s_p;
	t_discrim	d;
	// t_vec		intp;//レイと円柱の交点位置

	// s_p = diff_vec(ray->position, cy->position);
	d.a = inner_vec(ray->direction, ray->direction)
		- pow(inner_vec(cy->direction, ray->direction), 2);
	// d.b = 2 * inner_vec(outer_vec(ray->direction, cy->direction)),
	// 	outer_vec((s_p, cy->direction));
	// d.c = square_sum((outer_vec(s_p, cy->direction), outer_vec(s_p, cy->direction))) * square_sum((outer_vec(s_p, cy->direction), outer_vec(s_p, cy->direction))) - (cy->radius * cy->radius);
	d.discrim = d.b * d.b - 4 * d.a * d.c;
	d.t = -1.0f;
	if (d.discrim >= 0)
		cy_squrt_discriminant(&d);
	// d.m = inner_vec(s_p, cy->direction)
	// 	+ d.t * inner_vec(ray->direction, cy->direction);
	// intp = (add_vec(ray->position, mult_vec(ray->direction, d.t)));
	// to_center = intp - cy->position
	d.m = inner_vec((add_vec(ray->position, mult_vec(ray->direction, d.t)), cy->direction), cy->direction);
	if (d.m < -cy->height / 2 || d.m > cy->height / 2)
		d.t = -1;
	return (d);
}

bool	intersection_cylinder(const t_object *object, const t_ray *ray,
	t_intersect *info)
{
	const t_cylinder	*cylinder;
	t_discrim			d;
	t_vec				pos_diff;
	t_vec				projection;

	if (object->type != ST_CYLINDER)
		return (false);
	cylinder = object->u_data.cylinder;
	d = cy_discriminant(ray, cylinder);
	printf("Cylinder radius: %f\n", cylinder->radius);
    printf("Discriminant: %f\n", d.discrim);
    printf("t1: %f, t2: %f\n", d.t1, d.t2);
	if (d.t > 0)//in out のflag持って if (flag = non) else//inかoutだったら　　in: (cy->dir * d.m) - (to_center = intp - cy->position)
	{
		if (info)
		{
			info->distance = d.t;
			info->position = add_vec(ray->position,
					mult_vec(ray->direction, d.t));
			pos_diff = diff_vec(info->position, cylinder->position);
			projection = mult_vec(cylinder->direction,
					inner_vec(pos_diff, cylinder->direction));
			info->normal = normalize_vec(diff_vec(pos_diff, projection));
		}
		return (true);
	}
	return (false);
}


/* 元のコード
void	cy_squrt_discriminant(t_discrim *d)
{
	double	squrt_discrim;

	squrt_discrim = sqrt(d->discrim);
	d->t1 = (-d->b - squrt_discrim) / (2 * d->a);
	d->t2 = (-d->b + squrt_discrim) / (2 * d->a);
	d->t = -1.0f;
	if (d->t1 > 0 && (d->t < 0 || d->t1 < d->t))
		d->t = d->t1;
	if (d->t2 > 0 && (d->t < 0 || d->t2 < d->t))
		d->t = d->t2;
}

static t_discrim	cy_discriminant(const t_ray *ray, const t_cylinder *cy)
{
	t_vec		s_p;
	t_discrim	d;

	s_p = diff_vec(ray->position, cy->position);
	d.a = inner_vec(ray->direction, ray->direction)
		- pow(inner_vec(cy->direction, ray->direction), 2);
	d.b = inner_vec(ray->direction, cy->direction)
		- inner_vec(ray->direction, cy->direction)
		* inner_vec(s_p, cy->direction);
	d.c = inner_vec(s_p, s_p) - pow(inner_vec(s_p, cy->direction), 2)
		- pow(cy->radius, 2);
	d.discrim = d.b * d.b - 4 * d.a * d.c;
	d.t = -1.0f;
	if (d.discrim >= 0)
		cy_squrt_discriminant(&d);
	d.m = inner_vec(s_p, cy->direction)
		+ d.t * inner_vec(ray->direction, cy->direction);
	if (d.m < -cy->height / 2 || d.m > cy->height / 2)
		d.t = -1;
	return (d);
}
*/