/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:35:21 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/04 17:07:49 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../srcs/libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "vector.h"
# include "light.h"
# include "shape.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>
# include <libc.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <ctype.h>
# include <stdbool.h>
# include <float.h>
# include <math.h>

# define WINDOW_WIDTH 400
# define WINDOW_HEIGHT 400

# define ERR_ARGC	"wrong argc."

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	double	window_width;
	double	window_height;
	int		bits_par_pixel;
	int		bytes_par_pixel;
	int		bytes_par_line;
	int		endian;
	t_scene	*scene;
}	t_vars;

//close
int	close_window_esc(int keycode, t_vars *vars);
int	close_window_x(t_vars *vars);

#endif