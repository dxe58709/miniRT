/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 00:32:10 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_plane(t_scene *scene);
bool	init_sphere(t_scene *scene);
bool	init_cylinder(t_scene *scene);

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static bool	correct_fname(const char *str, const char *suffix)
{
	size_t	str_len;
	size_t	suffix_len;

	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);

	if (suffix_len > str_len)
		return (false);
	if (ft_strcmp(str + str_len - suffix_len, suffix) == 0)
		return (true);
	return (false);
}

char	*file_name(char *rt)
{
	char	*filename;

	if (!(correct_fname(rt, ".rt")))
	{
		print_error(ERR_FNAME, true);
		return (0);
	}
	filename = ft_strrchr(rt, '/');
	if (filename)
		filename++;
	else
		filename = rt;
	return (filename);
}

bool	correct_identifier(const char **argv, t_scene *scene)
{
	// if (!ft_memcmp(argv[0], "A", 2))
	// 	return (init_ambient_light());
	// else if (!ft_memcmp(argv[0], "C", 2))
	// 	return (init_camera(scene));
	// else if (!ft_memcmp(argv[0], "L", 2))
	// 	return (init_light(scene));
	if (!ft_memcmp(argv[0], "pl", 3))
		return (init_plane(scene));
	else if (!ft_memcmp(argv[0], "sp", 3))
		return (init_sphere(scene));
	else if (!ft_memcmp(argv[0], "cy", 3))
		return (init_cylinder(scene));
	return (false);
}