/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:39:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/08/05 20:38:57 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	destroy_mlx(t_vars *vars, char *msg)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	// free_scene(vars->scene);
	print_error(msg, true);
}

void	init_mlx(t_vars *vars, char *style)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		destroy_mlx(vars, ERR_INIT_MLX);
	vars->window_height = WINDOW_HEIGHT;
	vars->window_width = WINDOW_WIDTH;
	vars->win = mlx_new_window(vars->mlx, vars->window_width, \
									vars->window_height, style);
	if (!vars->win)
		destroy_mlx(vars, ERR_INIT_MLX);
	vars->img = mlx_new_image(vars->mlx, vars->window_width, \
									vars->window_height);
	if (!vars->img)
		destroy_mlx(vars, ERR_INIT_MLX);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_par_pixel, \
										&vars->bytes_par_line, &vars->endian);
}
