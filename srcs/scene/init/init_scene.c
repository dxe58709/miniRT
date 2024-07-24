/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:04:29 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 15:14:30 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	get_next_line(int fd, char **line);
void	free_result(char ***result);
bool	rt_split(const char *str, char ***result);
void	free_scene(t_scene *scene);
bool	correct_identifier(const char **argv, t_scene *scene);

static int	get_fd(char *rt)
{
	int		fd;

	if (!file_name(rt))
		print_error(ERR_FNAME, false);
	fd = open(rt, O_RDWR);
	if (fd < 0)
		print_error(ERR_FD, false);
	return (fd);
}

static void	set_scene(t_vars *vars)
{
	t_scene	*scene;

	scene = NULL;
	scene = vars->scene;
	vars->window_height = WINDOW_HEIGHT;
	vars->window_width = WINDOW_WIDTH;
	scene->sphere = NULL;
	scene->plane = NULL;
	scene->cylinder = NULL;
	scene->basis.center = mult_vec(scene->camera.camera_dir,
			-1 * vars->window_width / (2 * tan(scene->camera.fov / 360 * M_PI)));
}

static bool	scene_setting(t_scene *scene, char *line)
{
	char	**splite_str;
	bool	is_correct;

	splite_str = NULL;
	if (*line)
	{
		free(line);
		return (true);
	}
	if (!rt_split(line, &splite_str))
	{
		free(line);
		return (false);
	}
	free(line);
	is_correct = correct_identifier((const char **)splite_str, scene);
	free_result(&splite_str);
	return (is_correct);
}

void	init_scene(t_vars *vars, char *rt)
{
	int		fd;
	char	*line;
	t_scene	*scene;

	fd = get_fd(rt);
	scene = ft_calloc(1, sizeof(t_scene));
	errno = 0;
	while (get_next_line(fd, &line))
	{
		if (!scene_setting(scene, line))
		{
			free_scene(scene);
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
	vars->scene = scene;
	set_scene(vars);
	set_basis(&scene->basis);
}
