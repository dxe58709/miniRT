/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:14:54 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/14 22:28:20 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_rgb	encode_rgb_values(char **split)
{
	t_rgb	rgb;

	rgb.red = ft_atoi(split[0]);
	rgb.green = ft_atoi(split[1]);
	rgb.blue = ft_atoi(split[2]);

	return (rgb);
}

t_rgb	process_rgb_str(char *str)
{
	t_rgb	rgb;
	char	**split;
	size_t	i;

	split = ft_split(str, ',');
	if (split == NULL)
		print_err_exit(ERR_MALLOC);

	i = 0;
	while (split[i])
	{
		if (ft_atoi(split[i]) < 0 || 255 < ft_atoi(split[i]))
			print_err_exit("Error : rgb is out of range\n");
		i++;
	}
	if (i != 3)
		print_err_exit(ERR_RGB_ARGC);

	rgb = encode_rgb_values(split);
	free_split(split);
	return (rgb);
}
