/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:39:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/08/09 15:51:23 by nsakanou         ###   ########.fr       */
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
	vars->win = mlx_new_window(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, style);
	if (!vars->win)
		destroy_mlx(vars, ERR_INIT_MLX);
	vars->img = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!vars->img)
		destroy_mlx(vars, ERR_INIT_MLX);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_par_pixel, \
										&vars->bytes_par_line, &vars->endian);
}

void	pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->bytes_par_line
			+ x * (vars->bytes_par_pixel) / 8);
	*(unsigned int *)dst = color;
}

void	set_hook(t_vars *vars)
{
	draw(vars);
	mlx_key_hook(vars->win, close_window_esc, vars);
	mlx_hook(vars->win, 17, 1L << 0, close_window, (void *)vars);
	mlx_loop(vars->mlx);
	exit (0);
}
