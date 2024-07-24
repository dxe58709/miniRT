/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:47:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 14:22:52 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	count_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	split_count(char **split, size_t expected, char *err_msg)
{
	size_t	count;

	count = count_split(split);
	if (count != expected)
		print_err_exit(err_msg);
}
