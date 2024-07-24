/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:32:50 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 16:39:42 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_in_range_double(double value, double min, double max)
{
	return (min <= value && value <= max);
}

double	check_atof_range(char *str, double min, double max)
{
	double	value;

	value = ft_atof(str);
	if (!is_in_range_double(value, min, max))
		print_err_exit("Invalid out of range");
	return (value);
}
