/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:03:17 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/14 22:36:22 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strcmp(const char *s1, const char *s2)
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

static char	*file_name(char *rt)
{
	char	*filename;

	if (!(correct_fname(rt, ".rt")))
	{
		print_err_exit(ERR_FNAME);
		return (0);
	}
	filename = ft_strrchr(rt, '/');
	if (filename)
		filename++;
	else
		filename = rt;
	return (filename);
}

static void	check_file_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (0 <= fd)
	{
		close(fd);
		ft_putstr_fd("Error: is a directory", 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
}

int	get_fd(char *rt)
{
	int		fd;

	check_file_directory(rt);
	if (!file_name(rt))
		print_err_exit(ERR_FNAME);
	fd = open(rt, O_RDWR);
	if (fd < 0)
		print_err_exit(ERR_FD);
	return (fd);
}
