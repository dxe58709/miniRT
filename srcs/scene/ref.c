/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:25:13 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/24 22:04:30 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_ref(t_ref *ref)
{
	init_rgb(&ref->ambient_ref, 0.1, 0.1, 0.1);
	init_rgb(&ref->specular_ref, 0.3, 0.3, 0.3);
	ref->gloss = 8.0;
}
