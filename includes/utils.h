/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:00:11 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 21:45:04 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

//close
int		close_window_esc(int keycode, t_vars *vars);
int		close_window_x(t_vars *vars);
void	close_window(t_vars *vars);

//mlx
void	init_mlx(t_vars *vars, char *style);
void	pixel_put(t_vars *vars, int x, int y, int color);
void	set_hook(t_vars *vars);
void	draw(t_vars *vars);

//utils
void	print_error(char *msg, bool is_true);
void	print_err_exit(char *str);

//split
void	split_count(char **split, size_t expected, char *err_msg);
size_t	count_split(char **split);
char	**split_space(char *line);
char	**split_comma(char *line);

//rt_atof
double	check_atof_range(char *str, double min, double max);
bool	is_in_range_double(double value, double min, double max);

//init_scene_utils
char	*file_name(char *rt);

#endif