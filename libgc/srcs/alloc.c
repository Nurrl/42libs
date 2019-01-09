/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:09:58 by lroux             #+#    #+#             */
/*   Updated: 2019/01/08 17:12:41 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.intern.h"

void	*smalloc(size_t size)
{
	t_alist *node;

	if (!(node = malloc(sizeof(*node))))
		return (NULL);
	node->next = 0;
	node->address = malloc(size);
	node->size = size;
	if (node->address)
		listpush(node);
	else
		free(node);
	return (node->address);
}

void	sfree(void *ptr)
{
	t_alist *node;

	if (!ptr || !(node = listpop(ptr)))
		return ;
	free(node->address);
	free(node);
}

size_t	sizealloc(void *ptr)
{
	t_alist *head;

	head = listhead()->next;
	while (head)
	{
		if (head->address == ptr)
			return (head->size);
		head = head->next;
	}
	return (-1);
}
