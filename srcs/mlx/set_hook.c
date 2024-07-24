/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:35:16 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 21:52:03 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	loop_hook(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

void	set_hook(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, &loop_hook, vars);
	mlx_key_hook(vars->win, close_window_esc, vars);
	mlx_hook(vars->win, 17, 1L << 0, close_window_x, (void *)vars);
	mlx_loop(vars->mlx);
	exit (0);
}
