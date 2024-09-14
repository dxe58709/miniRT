/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:14:42 by nsakanou          #+#    #+#             */
/*   Updated: 2024/09/14 22:54:30 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane		*set_plane(char *line);
t_sphere	*set_sphere(char *line);
t_cylinder	*set_cylinder(char *line);

t_object	*init_object(void)
{
	t_object	*new_object;

	new_object = ft_calloc(1, sizeof(t_object));
	if (!new_object)
		print_err_exit(ERR_MALLOC);
	return (new_object);
}

// t_object	*obj_list_new(t_shape_type type, char *line)
// {
// 	t_object	*new;

// 	new = ft_calloc(1, sizeof(t_object));
// 	if (!new)
// 		print_err_exit(ERR_MALLOC);
// 	new->next = NULL;
// 	new->type = type;
// 	if (type == ST_PLANE)
// 		new->u_data.plane = (void *)set_plane(line);
// 	else if (type == ST_SPHERE)
// 		new->u_data.sphere = (void *)set_sphere(line);
// 	else if (type == ST_CYLINDER)
// 		new->u_data.cylinder = (void *)set_cylinder(line);
// 	else
// 		print_err_exit(ERR_OBJ_TYPE);
// 	return (new);
// }

t_object	*obj_list_new(t_shape_type type, char *line)
{
	t_object	*new;

	new = ft_calloc(1, sizeof(t_object));
	if (!new)
		print_err_exit(ERR_MALLOC);
	new->next = NULL;
	new->type = type;
	if (type == ST_PLANE)
	{
		new->u_data.plane = set_plane(line);

		// デバッグ用の出力
		printf("Plane Created: Position (%.2f, %.2f, %.2f), Normal (%.2f, %.2f, %.2f)\n",
			new->u_data.plane->position.x,
			new->u_data.plane->position.y,
			new->u_data.plane->position.z,
			new->u_data.plane->normal.x,
			new->u_data.plane->normal.y,
			new->u_data.plane->normal.z);
	}
	else if (type == ST_SPHERE)
	{
		new->u_data.sphere = set_sphere(line);

		// デバッグ用の出力
		printf("Sphere Created: Position (%.2f, %.2f, %.2f), Radius %.2f\n",
			new->u_data.sphere->position.x,
			new->u_data.sphere->position.y,
			new->u_data.sphere->position.z,
			new->u_data.sphere->radius);
	}
	else if (type == ST_CYLINDER)
	{
		new->u_data.cylinder = set_cylinder(line);

		// デバッグ用の出力
		printf("Cylinder Created: Position (%.2f, %.2f, %.2f), Radius %.2f, Height %.2f\n",
			new->u_data.cylinder->position.x,
			new->u_data.cylinder->position.y,
			new->u_data.cylinder->position.z,
			new->u_data.cylinder->radius,
			new->u_data.cylinder->height);
	}
	else
	{
		print_err_exit(ERR_OBJ_TYPE);
	}
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

void	obj_list_addback(t_object **head, t_object *new_node)
{
	t_object	*last_node;

	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = object_last_node(*head);
		last_node->next = new_node;
	}
	new_node->next = NULL;
}

void	free_object_node(t_object *head)
{
	t_object	*tmp;
	t_object	*node;

	if (!head)
		return ;
	node = head->next;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (tmp->type == ST_PLANE)
			free(tmp->u_data.plane);
		else if (tmp->type == ST_SPHERE)
			free(tmp->u_data.sphere);
		else if (tmp->type == ST_CYLINDER)
			free(tmp->u_data.cylinder);
		free(tmp);
	}
	free(head);
}
