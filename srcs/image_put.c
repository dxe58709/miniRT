/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:06:39 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/11 18:39:31 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec	camera_direction(t_vars *vars, int x, int y)
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

int	img_put(t_vars *vars)
{
	int		x;
	int		y;
	t_rgb	rgb;
	t_ray	camera;

	vars->window_height = 800;
	vars->window_width = 800;
	y = 0;
	while (y < vars->window_height)
	{
		x = 0;
		while (x < vars->window_width)
		{
			//視点位置から点(x,y)に向かう半直線と物体との交差判定を行う
			camera.start = vars->scene->camera_pos;
			camera.direction = camera_direction(vars, x, y);
			set_color(&rgb);//色０にセットできてないかも
    // if (半直線が物体と交差する場合)
    // {
    //   if ( 物体の交点と公言の間に他の物体がない )
    //     4a. シェーディングの処理を行う(図1-3a)．
    //   else
    //     4b. 影として扱う(図1-3b)．
    // }
    // else
    // {
    //   4c. 次の点を処理する(背景色として扱う，図1-3c)．
    // }
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
