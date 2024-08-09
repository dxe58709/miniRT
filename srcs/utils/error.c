/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:54:21 by nsakanou          #+#    #+#             */
/*   Updated: 2024/08/09 16:31:20 by nsakanou         ###   ########.fr       */
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

void	print_err_exit(char *str)
{
	ft_putstr_fd("ERROR: ", 2);
	perror(str);
	exit(1);
}
