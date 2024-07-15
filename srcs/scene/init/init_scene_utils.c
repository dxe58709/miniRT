/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:41:13 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/15 10:47:21 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		print_error("ERR_FILE", true);
		return (0);
	}
	filename = ft_strrchr(rt, '/');
	if (filename)
		filename++;
	else
		filename = rt;
	return (filename);
}