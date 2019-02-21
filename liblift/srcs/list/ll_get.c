/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:22:21 by lroux             #+#    #+#             */
/*   Updated: 2019/02/21 14:22:53 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/list.h"

t_node	*ll_get(t_node *head, int id)
{
	t_bool	negative;
	t_node	*cur;

	if (!head)
		return (NULL);
	negative = false;
	if (id < 0)
		negative = true;
	if (negative)
		id = -id;
	cur = head;
	while (id--)
		cur = (negative) ? cur->prev : cur->next;
	return (cur);
}
