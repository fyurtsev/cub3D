/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:17:40 by eyagiz            #+#    #+#             */
/*   Updated: 2023/01/18 15:12:44 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_maplist	*create_list(void)
{
	t_maplist	*list;

	list = (t_maplist *)malloc(sizeof(t_maplist));
	if (!list)
		system_err("Malloc Error");
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_node	*create_node(char *line)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		system_err("Malloc Error");
	node->map = ft_strdup(line);
	node->next = NULL;
	return (node);
}

void	add_node(t_maplist *list, t_node *node)
{
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
}
