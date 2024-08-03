/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:34:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/08/04 00:22:26 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*init_object(void);
void		init_scene(t_vars *vars, char *rt);
void		free_object_node(t_object *head);

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
    if (!vars)
    {
        print_err_exit("Memory allocation failed for vars");
        return (1);
    }
    vars->scene = (t_scene *)malloc(sizeof(t_scene)); // Assuming t_scene is the struct type of scene
    if (!vars->scene)
    {
        free(vars);
        print_err_exit("Memory allocation failed for scene");
        return (1);
    }
	if (argc != 2)
		print_err_exit(ERR_ARGC);
	vars->scene->object = init_object();
	init_scene(vars, argv[1]);
	init_mlx(vars, argv[1]);
	draw(vars);
	set_hook(vars);
	close_window(vars);
	free_object_node(vars->scene->object);
	return (0);
}
