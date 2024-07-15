/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:41:59 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/15 11:02:32 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_scene(vars->scene);
}

int	close_window_esc(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_window(vars);
	return (0);
}

int	close_window_x(t_vars *vars)
{
	close_window(vars);
	return (0);
}
