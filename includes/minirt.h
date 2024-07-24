/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:35:21 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 19:13:24 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "vector.h"
# include "utils.h"
# include "shape.h"
# include <stdlib.h>
# include <fcntl.h>
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
# include <errno.h>

# define WINDOW_WIDTH 400
# define WINDOW_HEIGHT 400

# define ERR_ARGC		"wrong argc."
# define ERR_INIT_MLX	"mlx initialization failed."
# define ERR_RTFILE_FMT "Unexpected comma at the end of the string"
# define ERR_FNAME		"Unexpocted FileName"
# define ERR_FD 		"File does not exit"
# define ERR_INVALID_PARAMS "Not invalid params"
# define ERR_MALLOC		"Failed to malloc"
# define ERR_PLANE_ARGC	"Failed to Plane Argument"
# define ERR_SPHERE_ARGC	"Failed to Sphere Argument"
# define ERR_CYLINDER_ARGC	"Failed to Cylinder Argument"
# define ERR_CAMERA_ARGC	"Failed to camera Argument"
# define ERR_AMBIENT_ARGC	"Failed to ambient Argument"
# define ERR_LIGHT_ARGC	"Failed to light Argument"
# define ERR_RGB_ARGC	"Failed to color Argument"
# define ERR_OBJ_TYPE	"Invalid object type"

typedef struct s_object
{
	t_shape_type	type;
	void			*object_data;
	struct s_object	*next;
}	t_object;

typedef struct s_scene {
	t_ref			*ref;
	t_light			light;
	t_ambient		ambients;
	t_camera		camera;
	t_basis			basis;//いらんかも
	t_object		*object;
}	t_scene;

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

# define BUFFER_SIZE 100

#endif