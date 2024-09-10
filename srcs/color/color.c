/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:03:05 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/10 18:43:23 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_split(char **split);

void	init_rgb(t_rgb *rgb, double r, double g, double b)
{
	rgb->red = r;
	rgb->green = g;
	rgb->blue = b;
}

int	encode_rgb(t_rgb rgb)
{
	return ((int)rgb.red << 16 | (int)rgb.green << 8 | (int)rgb.blue);
}

int	encode_rgb_values(char **split)
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
		print_err_exit("Error : rgb is out of range\n");
}

int	process_rgb_str(char *str)
{
	int		rgb;
	char	**split;
	size_t	i;

	split = ft_split(str, ',');
	if (split == NULL)
		print_err_exit(ERR_MALLOC);
	i = 0;
	while (split[i])
	{
		check_rgb_range(split[i]);
		i++;
	}
	if (i != 3)
		print_err_exit(ERR_RGB_ARGC);
	rgb = encode_rgb_values(split);
	free_split(split);
	return (rgb);
}
