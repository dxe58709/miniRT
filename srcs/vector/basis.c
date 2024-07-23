/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:23:21 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/23 23:32:15 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_basis(t_basis *basis)
{
	if (basis->center.x == 0 && basis->center.z == 0)
	{
		basis->up = normalize_vec(outer_vec(init_vector(0.0, 0.0, 1.0),
					normalize_vec(basis->center)));
		basis->vertical = normalize_vec(outer_vec
				(normalize_vec(basis->center), basis->up));
	}
	else
	{
		basis->up = normalize_vec(outer_vec(init_vector(0.0, 1.0, 0.0),
					normalize_vec(basis->center)));
		basis->vertical = normalize_vec(outer_vec
				(normalize_vec(basis->center), basis->up));
	}
}
