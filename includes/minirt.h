/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:35:21 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 00:31:02 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "vector.h"
# include "light.h"
# include "color.h"
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

# define ERR_ARGC	"wrong argc."
# define ERR_INIT_MLX	"mlx initialization failed."

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

//レイトレーシングの計算
typedef struct s_rt_info {
	t_vec		light;//光源から交差点へのベクトル
	t_vec		visual;//視線ベクトル
	t_vec		ref;//反射ベクト
	t_ray		shadow_ray;//影の光線
	double		dl;//距離の変数
	double		nl_dot;//法線ベクトルと光源ベクトルの内積
	double		vr_dot;//視線ベクトルと反射ベクトルの内積
	double		vr_dot_pow;//内積の累乗値
}	t_rt_info;

//レイトレーシングの計算に必要なすべての情報を統合
// typedef struct s_rt {
// 	t_rt_info		info;
// 	t_light			*light;
// 	t_shape_type	type;
// }	t_rt;

# define BUFFER_SIZE 100

# define ERR_RTFILE_FMT "Unexpected comma at the end of the string"
# define ERR_FNAME		"Unexpocted FileName"
# define ERR_FD 		"File does not exit"
# define ERR_INVALID_PARAMS "Not invalid params"

//close
int		close_window_esc(int keycode, t_vars *vars);
int		close_window_x(t_vars *vars);
void	close_window(t_vars *vars);

//mlx
void	init_mlx(t_vars *vars, char *style);
void	pixel_put(t_vars *vars, int x, int y, int color);
void	set_hook(t_vars *vars);
void	img_put(t_vars *vars);

//camera
t_ray	get_camera_ray(const t_scene *scene, double u,
			double v, double aspect);

//utils
void	print_error(char *msg, bool is_true);
void	free_scene(t_scene *scene);
size_t	count_argc(char **split);

//scene
char	*file_name(char *rt);

#endif