/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:14:42 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/10 20:32:54 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane		*init_plane(char *line);
t_sphere	*init_sphere(char *line);
t_cylinder	*init_cylinder(char *line);

t_object	*init_object(void)
{
	t_object	*new_object;

	new_object = ft_calloc(1, sizeof(t_object));
	if (!new_object)
		print_err_exit(ERR_MALLOC);
	return (new_object);
}

t_object	*obj_list_new(t_shape_type type, char *line)
{
	t_object	*new;

	new = ft_calloc(1, sizeof(t_object));
	if (!new)
		print_err_exit(ERR_MALLOC);
	new->next = NULL;
	new->type = type;
	if (type == ST_PLANE)
		new->object_data = (void *)init_plane(line);
	else if (type == ST_SPHERE)
		new->object_data = (void *)init_sphere(line);
	else if (type == ST_CYLINDER)
		new->object_data = (void *)init_cylinder(line);
	else
		print_err_exit(ERR_OBJ_TYPE);
	return (new);
}

t_object	*object_last_node(t_object *head)
{
	t_object	*node;

	node = head;
	while (node && node->next)
		node = node->next;
	return (node);
}

void	obj_list_addback(t_object *head, t_object *new_node)
{
	t_object	*last_node;

	last_node = object_last_node(head);
	if (!last_node)
		last_node = ft_calloc(1, sizeof(t_object));
	last_node->next = new_node;
	new_node->next = NULL;
}

void	free_object_node(t_object *head)
{
	t_object	*tmp;
	t_object	*node;

	node = head->next;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp->object_data);
		free(tmp);
	}
	free(head);
}
