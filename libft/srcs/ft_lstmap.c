/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:24:46 by lroux             #+#    #+#             */
/*   Updated: 2018/11/12 15:59:37 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*iter;

	if (!lst)
		return (NULL);
	if (!(start = f(lst)))
		return (NULL);
	iter = start;
	while (lst->next)
	{
		lst = lst->next;
		if (!(iter->next = f(lst)))
			return (NULL);
		iter = iter->next;
	}
	return (start);
}
