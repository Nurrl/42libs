/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ladd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 07:09:02 by lroux             #+#    #+#             */
/*   Updated: 2019/02/21 14:26:42 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/list.h"
#include "lift/memory.h"

void	ll_add(t_node **head, void *data)
{
	t_node *new;

	if (!(new = ft_calloc(1, sizeof(*new))))
		return ;
	new->data = data;
	if (!*head)
		new->next = new;
	else
		new->next = *head;
	if (!*head)
		new->prev = new;
	else
		new->prev = (*head)->prev;
	if (!*head)
		*head = new;
	(*head)->prev->next = new;
	(*head)->prev = new;
}
