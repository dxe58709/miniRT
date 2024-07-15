/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:54:21 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/11 17:15:49 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(char *msg, bool is_true)
{
	if (is_true && errno != 0)
		perror(msg);
	else
		ft_putendl_fd(msg, STDERR_FILENO);
	exit (EXIT_FAILURE);
}