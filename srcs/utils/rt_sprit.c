/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sprit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:28:38 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 15:24:08 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_split(char **split)
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

static char	*change_single_space(char *line)
{
	char	*result;
	size_t	i;

	result = ft_strdup(line);
	if (result == NULL)
		print_err_exit(ERR_MALLOC);
	i = 0;
	while (result[i])
	{
		if (ft_isspace(result[i]))
			result[i] = ' ';
		i++;
	}
	return (result);
}

char	**split_space(char *line)
{
	char	**split;
	char	*result;

	result = change_single_space(line);
	split = ft_split(result, ' ');
	if (split == NULL)
		print_err_exit(ERR_MALLOC);
	free(result);
	return (split);
}

char	**split_comma(char *line)
{
	char	**split;

	split = ft_split(line, ',');
	if (split == NULL)
		print_err_exit(ERR_MALLOC);
	return (split);
}
