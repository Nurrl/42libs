/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:08:17 by lroux             #+#    #+#             */
/*   Updated: 2019/08/06 17:12:16 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/list.h"

/*
** Implemtation of quicksort on circular double linked lists.
** Help: https://dojo.stuycs.org/resources/_images/quicksort.gif
*/

static t_node	*partition(t_cmp handler, t_node *head, t_node *pivot)
{
	t_node *l;
	t_node *r;

	l = head;
	r = pivot;
	while (l != r && (r != head || l->next != pivot))
	{
		if (handler(l->data, pivot->data))
			l = l->next;
		else if (handler(pivot->data, r->data))
			r = r->prev;
		else
			ll_swap(l, r);
	}
	ll_swap(l, pivot);
	return (l);
}

void			ll_qsort(t_cmp handler, t_node *head, t_node *pivot)
{
	t_node *split;

	split = partition(handler, head, pivot);
	if (split != head)
		ll_qsort(handler, head, split->prev);
	if (split != pivot)
		ll_qsort(handler, split->next, pivot);
}
