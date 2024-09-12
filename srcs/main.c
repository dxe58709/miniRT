/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:34:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/12 17:47:21 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*init_object(void);
void		init_scene(t_vars *vars, char *rt);
void		free_object_node(t_object *head);
void		set_hook(t_vars *vars);
int			close_window(t_vars *vars);

void print_object_data(t_object *obj)
{
    if (!obj) {
        printf("Object is NULL\n");
        return;
    }

    printf("[Object type: %d]\n", obj->type);

    if (obj->object_data) {
        switch (obj->type) {
            case ST_PLANE:
                {
                    t_plane *plane = (t_plane *)obj->object_data;
                    printf("  Plane position: (%f, %f, %f)\n", plane->position.x, plane->position.y, plane->position.z);
                    // 他の plane に関連する情報を表示
                }
                break;
            case ST_SPHERE:
                {
                    t_sphere *sphere = (t_sphere *)obj->object_data;
                    printf("  Sphere center: (%f, %f, %f)\n", sphere->center.x, sphere->center.y, sphere->center.z);
                    printf("  Sphere radius: %f\n", sphere->radius);
                    // 他の sphere に関連する情報を表示
                }
                break;
            case ST_CYLINDER:
                {
                    t_cylinder *cylinder = (t_cylinder *)obj->object_data;
                    printf("  Cylinder position: (%f, %f, %f)\n", cylinder->position.x, cylinder->position.y, cylinder->position.z);
                    printf("  Cylinder height: %f\n", cylinder->height);
                    // 他の cylinder に関連する情報を表示
                }
                break;
            default:
                printf("  Unknown object type\n");
                break;
        }
    } else {
        printf("  Object data is NULL\n");
    }
}

void print_scene(t_scene *scene)
{
    if (!scene) {
        printf("Scene is NULL\n");
        return;
    }
    printf("Scene:\n");

    // t_lightの確認
    printf("  Light position: (%f, %f, %f)\n", scene->light.position.x, scene->light.position.y, scene->light.position.z);
    printf("  Light intensity: %f\n", scene->light.ratio);

    // t_ambientの確認
    printf("  Ambient intensity: %f\n", scene->ambients.ratio);

    // t_cameraの確認
    printf("  Camera position: (%f, %f, %f)\n", scene->camera.camera_pos.x, scene->camera.camera_pos.y, scene->camera.camera_pos.z);
    printf("  Camera direction: (%f, %f, %f)\n", scene->camera.camera_dir.x, scene->camera.camera_dir.y, scene->camera.camera_dir.z);

    // t_objectの確認
    t_object *obj = scene->object;
    while (obj) {
        print_object_data(obj);  // 各オブジェクトのデータを表示
        obj = obj->next;
    }
}

void print_vars(t_vars *vars)
{
    if (!vars) {
        printf("Vars is NULL\n");
        return;
    }
    printf("Vars:\n");

    // mlx, win, imgの確認
    printf("  mlx pointer: %p\n", vars->mlx);
    printf("  win pointer: %p\n", vars->win);
    printf("  img pointer: %p\n", vars->img);

    // アドレスと画面サイズの確認
    printf("  addr pointer: %p\n", vars->addr);
    printf("  window width: %f\n", vars->window_width);
    printf("  window height: %f\n", vars->window_height);

    // ビット、バイト、エンディアンの確認
    printf("  bits per pixel: %d\n", vars->bits_par_pixel);
    vars->bytes_par_pixel = vars->bits_par_pixel / 8;
    printf("  bytes per pixel: %d\n", vars->bytes_par_pixel);
    printf("  bytes per line: %d\n", vars->bytes_par_line);
    printf("  endian: %d\n", vars->endian);

    // シーンの確認
    if (vars->scene) {
        print_scene(vars->scene);  // t_sceneの内容を表示
    } else {
        printf("  Scene is NULL\n");
    }
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		print_err_exit(ERR_ARGC);
	vars = ft_calloc(1, sizeof(t_vars));
	init_scene(vars, argv[1]);
	vars->scene->object = init_object();
	print_vars(vars);
	set_hook(vars);
	close_window(vars);
	free_object_node(vars->scene->object);
	free(vars);
	return (0);
}
