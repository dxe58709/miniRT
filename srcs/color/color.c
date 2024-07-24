/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:03:05 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 18:43:47 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_rgb(t_rgb *rgb, double r, double g, double b)
{
	rgb->red = r;
	rgb->green = g;
	rgb->blue = b;
}

static int	encode_rgb_values(char **split)
{
	char	*red;
	char	*green;
	char	*blue;

	red = split[0];
	green = split[1];
	blue = split[2];
	return (ft_atoi(red) << 16 | ft_atoi(green) << 8 | ft_atoi(blue));
}

static void	check_rgb_range(char *rgb)
{
	if (ft_atoi(rgb) < 0 || 255 < ft_atoi(rgb))
		print_err_exit("Error : rgb is out of range");
}

int	process_rgb_str(char *str)
{
	int		rgb;
	char	**split;
	size_t	i;

	split = ft_split(str, ',');
	if (split == NULL)
		print_error_and_exit(ERR_MALLOC);
	i = 0;
	while (split[i++])
		check_rgb_range(split[i]);
	if (i != 3)
		print_err_exit(ERR_RGB_ARGC);
	rgb = encode_rgb_values(split);
	free_split(split);
	return (rgb);
}
