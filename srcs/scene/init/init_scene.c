/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:04:29 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/15 10:43:03 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	get_fd(char *rt)
{
	int		fd;

	if (!file_name(rt))
		print_error("ERR_FNAME", false);
	fd = open(rt, O_RDWR);
	if (fd < 0)
		print_error("ERR_FD", false);
	return (fd);
}

static	void	compute_basis_vec(t_basis *basis)
{
	if (basis->center.x == 0 && basis->center.z == 0)
	{
		basis->up = normalize_vec(outer_vec(init_vector(0.0, 0.0, 1.0),
					normalize_vec(basis->center)));
		basis->vertical = normalize_vec(outer_vec(
					normalize_vec(basis->center), basis->up));
	}
}

static void	set_scene(t_vars *vars)
{
	t_scene	*scene;

	scene = vars->scene;
	vars->window_height = WINDOW_HEIGHT;
	vars->window_width = WINDOW_WIDTH;
	scene->basis.center = mult_vec(scene->camera_dir,
			-1 * vars->window_width / (2 * tan(scene->fov / 360 * M_PI)));
}

// static bool	scene_setting(t_scene *scene, char *line)
// {
	
// }

void	init_scene(t_vars *vars, char *rt)
{
	int		fd;
	char	*line;
	t_scene	*scene;

	fd = get_fd(rt);
	scene = sf_calloc(1, sizeof(t_scene));
	errno = 0;
	while (get_next_line(fd, &line))
	{
		//scene_settingじゃなかったらエラー
		//free_scene
	}
	close(fd);
	vars->scene = scene;
	set_scene(vars);
	compute_basis_vec(&scene->basis);
}
