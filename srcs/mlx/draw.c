/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:06:39 by nsakanou          #+#    #+#             */
/*   Updated: 2024/08/09 16:26:17 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		encode_rgb(t_rgb rgb);

static t_vec	get_camera_direction(t_vars *vars, int x, int y)
{
	t_vec	center;
	t_vec	u;
	t_vec	v;

	center = mult_vec(vars->scene->basis.center, -1);
	u = vars->scene->basis.up;
	v = vars->scene->basis.vertical;
	return (normalize_vec(\
				add_vec(\
					center, \
					add_vec(\
						mult_vec(u, (x - vars->window_width / 2)), \
						mult_vec(v, (-y + vars->window_height / 2)) \
					) \
				) \
			));
}

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->bytes_par_line
			+ x * (vars->bytes_par_pixel) / 8);
	*(unsigned int *)dst = color;
}

void	draw(t_vars *vars)
{
	int		x;
	int		y;
	t_ray	camera;
	t_rgb	color;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			camera.start = vars->scene->camera.camera_pos;
			vars->scene->camera.camera_dir = get_camera_direction(vars, x, y);
			init_rgb(&color, 0, 0, 0);
			//raytrace
			pixel_put(vars, x, y, encode_rgb(color));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
