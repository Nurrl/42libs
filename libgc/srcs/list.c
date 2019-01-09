/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:28:59 by lroux             #+#    #+#             */
/*   Updated: 2019/01/08 17:25:22 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.intern.h"

t_alist		*listhead(void)
{
	static t_alist	head;

	return (&head);
}

void		listpush(t_alist *node)
{
	t_alist *head;

	head = listhead();
	while (head->next)
		head = head->next;
	head->next = node;
}

t_alist		*listpop(void *address)
{
	t_alist *head;
	t_alist *node;

	if (!address)
		return (NULL);
	head = listhead();
	while (head->next)
	{
		if (head->next->address && head->next->address == address)
			break ;
		head = head->next;
	}
	node = head->next;
	head->next = head->next->next;
	return (node);
}

void		listeach(void (*h)(t_alist *node))
{
	t_alist *head;
	t_alist *node;

	head = listhead()->next;
	while (head)
	{
		node = head;
		head = head->next;
		h(node);
	}
}
