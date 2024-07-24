/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:34:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 22:15:08 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*init_object(void);
void		init_scene(t_vars *vars, char *rt);
void		free_object_node(t_object *head);

int	main(int argc, char **argv)
{
	t_vars	*vars;

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
