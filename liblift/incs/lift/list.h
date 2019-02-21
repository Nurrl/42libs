/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:32:09 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 16:32:53 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFT_LIST_H
# define LIFT_LIST_H

# include <stdlib.h>
# include <lift/types.h>

/*
**  _ _ _     _ _  __ _
** | (_) |   | (_)/ _| |
** | |_| |__ | |_| |_| |_
** | | | '_ \| | |  _| __|
** | | | |_) | | | | | |_
** |_|_|_.__/|_|_|_|  \__|
**
** Part `list`:
**   - Circular doubly linked list implementation.
**   - To use the initial t_node must be set to 0;
*/

typedef struct	s_node {
	void			*data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

void			ll_add(t_node **head, void *data);
t_node			*ll_dup(t_node *head);
t_node			*ll_get(t_node *head, int id);
void			*ll_pop(t_node **head, int id);

size_t			ll_len(t_node *head);
t_bool			ll_del(t_node **head);

#endif
