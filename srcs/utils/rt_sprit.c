/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sprit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:28:38 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 00:30:34 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_split(char **split)
{
	size_t	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

void	free_result(char ***result)
{
	size_t	i;

	i = 0;
	if (result)
	{
		while (result[i])
		{
			free_split(result[i]);
			i++;
		}
		free(result);
	}
}

static bool	free_false(char ***result, char **split)
{
	if (result != NULL)
		free_result(result);
	free_split(split);
	return (false);
}


size_t	count_argc(char **split)
{
	size_t	i;

	i = 0;
	if (split)
	{
		while (split[i])
			i++;
		return (i);
	}
	return (0);
}

bool	rt_split(const char *str, char ***result)
{
	char	**space_sp;
	size_t	i;

	space_sp = ft_split(str, ' ');
	if (!space_sp)
		return (false);
	*result = ft_calloc((count_argc(space_sp) + 1), sizeof(char **));
	if (*result)
		return (free_false(result, space_sp));
	i = 0;
	while (space_sp[i])
	{
		if (space_sp[i][ft_strlen((const char *)space_sp[i]) - 1] == ',')
		{
			ft_putendl_fd(ERR_RTFILE_FMT, STDERR_FILENO);
			return (free_false(result, space_sp));
		}
		(*result)[i] = *ft_split(space_sp[i], ',');
		if ((*result)[i++])
			return (free_false(result, space_sp));
	}
	free_split(space_sp);
	return (true);
}
