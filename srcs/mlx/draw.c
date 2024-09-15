/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:06:39 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/15 18:47:38 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		encode_rgb(t_rgb rgb);
void	color_mult(t_rgb *a, t_rgb b);
bool	get_nearest_shape(const t_scene *scene, const t_ray *ray,
			t_intersect *info);

static t_vec	get_camera_direction(t_vars *vars, int x, int y)
{
	t_vec	position;
	t_vec	u;
	t_vec	v;
	t_vec	direction;

	position = mult_vec(vars->scene->basis.center, -1);
	u = vars->scene->basis.up;
	v = vars->scene->basis.vertical;
	direction = normalize_vec(add_vec(position, add_vec(\
						mult_vec(u, (x - vars->window_width / 2)), \
						mult_vec(v, (-y + vars->window_height / 2)))));
	return (direction);
}

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->bytes_par_line + x * vars->bytes_par_pixel);
	*(unsigned int *)dst = color;
}

void	draw(t_vars *vars)
{
	int			x;
	int			y;
	t_ray		camera;
	t_rgb		color;
	t_intersect	info;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			camera.position = vars->scene->camera.position;
			camera.direction = get_camera_direction(vars, x, y);
			if (get_nearest_shape(vars->scene, &camera, &info))
			{
				color = info.object_color;
			}
			else
				init_rgb(&color, 0, 0, 0);
			// raytrace(vars, &camera, &color);
			pixel_put(vars, x, y, encode_rgb(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
