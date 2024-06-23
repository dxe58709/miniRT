/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:41:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/24 00:12:29 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static size_t	ptr_len(void **arr)
{
	size_t	len;

	len = 0;
	if (arr)
	{
		while (arr[len])
			len++;
	}
	return (len);
}

static void	free_ptr(void **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

// 与えられた文字列を解析し、t_vec型のポインタに変換
int	set_vec(t_vec *vec, char *str)
{
	char	**xyz;

	xyz = NULL;
	if (!(xyz = ft_split(str, ',')) || ptr_len((void**)xyz) != 3)
	{
		printf("input str: %s\n", str);
		free_ptr((void**)xyz);
		return (1);
	}
	vec->x = ft_atof(xyz[0]);
	vec->y = ft_atof(xyz[1]);
	vec->z = ft_atof(xyz[2]);
	return (0);
}
