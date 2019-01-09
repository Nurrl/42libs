/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgc.intern.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:15:18 by lroux             #+#    #+#             */
/*   Updated: 2019/01/08 15:31:55 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGC_INTERN_H
# define LIBGC_INTERN_H

# include "libgc.both.h"
# include <stdlib.h>

/*
** The libgc linked list to store all alloc'd pointers
*/

typedef struct	s_alist {
	void			*address;
	size_t			size;
	struct s_alist	*next;
}				t_alist;

/*
** Program destructor, called after
** every exit() or main's return();
*/
void			gcclean(void);

/*
** Functions that manipulates the list.
*/
t_alist			*listhead(void);
void			listpush(t_alist *node);
t_alist			*listpop(void *address);
void			listeach(void (*h)(t_alist *node));

#endif
