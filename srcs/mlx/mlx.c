/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:39:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/08/09 16:43:31 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw(t_vars *vars);
int		close_window_esc(int keycode, t_vars *vars);
int		close_window(t_vars *vars);

static void	destroy_mlx(t_vars *vars, char *msg)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	// free_scene(vars->scene);
	print_err_exit(msg);
}

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		destroy_mlx(vars, ERR_INIT_MLX);
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "minirt");
	if (!vars->win)
		destroy_mlx(vars, ERR_INIT_MLX);
	vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!vars->img)
		destroy_mlx(vars, ERR_INIT_MLX);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_par_pixel, \
										&vars->bytes_par_line, &vars->endian);
}

void	set_hook(t_vars *vars)
{
	draw(vars);
	mlx_key_hook(vars->win, close_window_esc, vars);
	mlx_hook(vars->win, 17, 1L << 0, close_window, (void *)vars);
	mlx_loop(vars->mlx);
	exit (0);
}
