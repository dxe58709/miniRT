/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:54:55 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/03 14:12:32 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "minirt.h"

typedef struct s_rgb
{
	double	red;
	double	green;
	double	blue;
}	t_rgb;

typedef enum e_light_type {
	LT_POINT,
	LT_DIRECTIONAL,
}	t_light_type;

typedef struct s_light {
	t_light_type	type;
	t_vec			vector;
	t_rgb			color_info;
	struct s_light	*next;
}	t_light;

#endif
