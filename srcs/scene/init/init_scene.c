/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:04:29 by nsakanou          #+#    #+#             */
/*   Updated: 2024/08/09 16:27:35 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool		get_next_line(int fd, char **line);
int			ft_strcmp(const char *s1, const char *s2);
t_ambient	init_ambient(char *line);
t_light		init_light(char *line);
t_camera	init_camera(char *line);
void		obj_list_addback(t_object *head, t_object *new_node);
t_object	*obj_list_new(t_shape_type type, char *line);
char		*file_name(char *rt);

static void	check_file_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (0 <= fd)
	{
		close(fd);
		ft_putstr_fd("Error: is a directory", 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
}

static int	get_fd(char *rt)
{
	int		fd;

	check_file_directory(rt);
	if (!file_name(rt))
		print_error(ERR_FNAME, false);
	fd = open(rt, O_RDWR);
	if (fd < 0)
		print_error(ERR_FD, false);
	return (fd);
}

static void	scene_setting(t_scene *scene, char *line)
{
	while (ft_isspace(*line))
		line++;
	if (ft_strncmp(line, "A", 1) == 0)
		scene->ambients = init_ambient(line);
	else if (ft_strncmp(line, "C", 1) == 0)
		scene->camera = init_camera(line);
	else if (ft_strncmp(line, "L", 1) == 0)
		scene->light = init_light(line);
	else if (ft_strncmp(line, "pl", 2) == 0)
		obj_list_addback(scene->object, obj_list_new(ST_PLANE, line));
	else if (ft_strncmp(line, "sp", 2) == 0)
		obj_list_addback(scene->object, obj_list_new(ST_SPHERE, line));
	else if (ft_strncmp(line, "cy", 2) == 0)
		obj_list_addback(scene->object, obj_list_new(ST_CYLINDER, line));
	else
		print_err_exit(ERR_OBJ_TYPE);
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
		if (ft_strcmp(line, "\n") == 0)
		{
			free(line);
			continue ;
		}
		scene_setting(scene, line);
		free(line);
	}
	close(fd);
	vars->scene = scene;
	scene->basis.center = mult_vec(scene->camera.camera_dir,
			1 * vars->window_width
			/ (2 * tan(scene->camera.fov / 360 * M_PI)));
	set_basis(&scene->basis);
}
