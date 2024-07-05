/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:41:59 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/05 15:04:12 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
}

int	close_window_esc(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		close_window(vars);
		free_scene();
	}
	return (0);
}

int	close_window_x(t_vars *vars)
{
	close_window(vars);
	free_scene();
	return (0);
}
