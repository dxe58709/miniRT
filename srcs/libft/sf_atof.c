/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:00:30 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/02 15:56:32 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	ft_error(void)
{
	printf("atof is error.\n");
	exit(-1);
}

static int	skip_sp_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

static double	read_integer(const char *str, int *i)
{
	double	nb;

	nb = 0;
	if (!ft_isdigit(str[*i]) || (str[*i] == '.' && str[*i + 1] == '\0'))
		ft_error();
	while (str[*i] && ft_isdigit(str[*i]) && str[*i] != '.')
	{
		nb = nb * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (nb);
}

static double	read_decimals(const char *str, int *i)
{
	double	decimals;
	double	nb;

	decimals = 0.1;
	nb = read_integer(str, i);
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] == '\0')
			ft_error();
		while (str[*i] && ft_isdigit(str[*i]))
		{
			nb = nb + ((str[*i] - '0') * decimals);
			decimals *= 0.1;
			(*i)++;
		}
	}
	return (nb);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	nb;

	sign = 1;
	i = skip_sp_sign(str, &sign);
	nb = read_decimals(str, &i);
	if (nb < -10000000000)
		ft_error();
	if (nb > 10000000000)
		ft_error();
	if (!ft_isdigit(str[i]) && str[i])
		ft_error();
	return (nb * sign);
}
