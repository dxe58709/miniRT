/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:39:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/05 15:09:30 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	destroy_mlx(t_vars *vars, bool destroy_window,
								bool destroy_display, char *msg)
{
	if (destroy_window)
		mlx_destroy_window(vars->mlx, vars->win);
	if (destroy_display)
		mlx_destroy_display(vars->mlx);
	free_scene(vars->scene);
	print_error(msg);
}

void	init_mlx(t_vars *vars, char *style)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		destroy_mlx(vars, false, false, "mlx initialization failed.\n");
	vars->win = mlx_new_window(vars->mlx, vars->window_width, \
									vars->window_height, style);
	if (vars->win == NULL)
		destroy_mlx(vars, false, true, "windows initialization failed.\n");
	vars->img = mlx_new_image(vars->mlx, vars->window_width, \
									vars->window_height);
	if (vars->img == NULL)
		destroy_mlx(vars, true, true, "image initialization failed.\n");
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_par_pixel, \
										&vars->bytes_par_line, &vars->endian);
}
