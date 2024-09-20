/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:27:47 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/19 21:11:22 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	intersection_plane(const t_object *object, const t_ray *ray,
			t_intersect *info);

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

/*
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
*/

void	cy_squrt_discriminant(t_discrim *d)
{
	if (d->discrim == 0)
		d->t = -d->b / (2 * d->a);
	else if (d->discrim > 0)
	{
		d->t1 = (-d->b + sqrt(d->discrim)) / (2 * d->a);
		d->t2 = (-d->b - sqrt(d->discrim)) / (2 * d->a);
		if (d->t1 > 0)
			d->t = d->t1;
		if (d->t2 > 0 && d->t2 < d->t)
			d->t = d->t2;
	}
	else
		d->t = -1.0f;
}

t_discrim	cy_discriminant(const t_ray *ray, const t_cylinder *cy)
{
	t_vec		s_p;
	t_vec		outer;
	t_discrim	d;

	outer = outer_vec(ray->direction, cy->direction);
	s_p = diff_vec(ray->position, cy->position);
	d.a = square_sum(outer);
	d.b = 2 * inner_vec(outer_vec(ray->direction, cy->direction),
			outer_vec(s_p, cy->direction));
	d.c = square_sum(outer_vec(s_p, cy->direction)) - pow(cy->radius, 2.0);
	d.discrim = d.b * d.b - 4 * d.a * d.c;
	cy_squrt_discriminant(&d);
	d.m = inner_vec(s_p, cy->direction)
		+ d.t * inner_vec(ray->direction, cy->direction);
	if (d.m < -cy->height / 2 || d.m > cy->height / 2)
		d.t = -1;
	return (d);
}

static void	set_out_intp_cylinder(t_intersect *out_intp, const t_cylinder *cy,
const t_ray *ray, t_discrim d)
{
	t_vec	to_center;
	t_vec	dot_direction;

	out_intp->distance = d.t;
	out_intp->position = add_vec(ray->position, \
								mult_vec(ray->direction, d.t));
	// シリンダーの中心から交差点までのベクトルを計算
	to_center = diff_vec(out_intp->position, cy->position);
    // シリンダーの方向ベクトルに沿った成分を計算
	dot_direction = mult_vec(cy->direction, inner_vec(to_center, cy->direction));
    // 交差点の法線ベクトルを計算
	out_intp->normal = diff_vec(to_center, dot_direction);
    // 法線ベクトルを正規化
	out_intp->normal = normalize_vec(out_intp->normal);
}

static void	set_out_intp(t_intersect *out_intp, t_intersect intp, bool *hit)
{
	*hit = true;
	*out_intp = intp;
}

//底面、上面の交差判定
static bool	inter_cy_planes(const t_object *object, const t_ray *ray,
t_intersect *out_intp)
{
	const t_cylinder	*cylinder;
	t_object			plane;
	bool				hit;
	t_intersect			info;
	t_plane				local_plane;

	hit = false;
	cylinder = object->u_data.cylinder;
	plane.u_data.plane = &local_plane;
	plane.u_data.plane->normal = mult_vec(cylinder->direction, -1);
	plane.u_data.plane->position = add_vec(cylinder->position,
			mult_vec(cylinder->direction, -1 * cylinder->height / 2));
	if (intersection_plane(&plane, ray, &info)
		&& abs_vec(diff_vec(info.position, plane.u_data.plane->position))
		<= cylinder->radius)
	{
		printf("inter position: (%f, %f, %f)\n", info.position.x, info.position.y, info.position.z);
        printf("inter distance: %f\n", info.distance);
		set_out_intp(out_intp, info, &hit);
	}
	plane.u_data.plane->normal = cylinder->direction;
	plane.u_data.plane->position = add_vec(cylinder->position,
			mult_vec(cylinder->direction, cylinder->height / 2));
	if (intersection_plane(&plane, ray, &info)
		&& abs_vec(diff_vec(info.position, plane.u_data.plane->position))
		<= cylinder->radius && (!hit || info.distance < out_intp->distance))
		set_out_intp(out_intp, info, &hit);
	return (hit);
}

bool	intersection_cylinder(const t_object *object, const t_ray *ray,
t_intersect *out_intp)
{
	const t_cylinder	*cylinder;
	t_discrim			d;

	cylinder = object->u_data.cylinder;
	d = cy_discriminant(ray, cylinder);
	if (inter_cy_planes(object, ray, out_intp))
	{
		if (d.t <= 0 || (d.t > 0 && out_intp->distance < d.t))
			return (true);
	}
	if (d.t > 0)
	{
		if (out_intp)
			set_out_intp_cylinder(out_intp, cylinder, ray, d);
		return (true);
	}
	else
		return (false);
}
