/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:54:55 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/15 10:26:37 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "color.h"
# include "minirt.h"

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
