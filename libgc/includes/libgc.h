/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 19:43:47 by lroux             #+#    #+#             */
/*   Updated: 2019/01/08 17:25:55 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGC_H
# define LIBGC_H

# include "libgc.both.h"
# include <stdlib.h>

/*
** Set usual functions as deprecated to prevent
** bypassing the garbage collector.
*/
void	*malloc(size_t size) __attribute__
	((deprecated("you\x20may\x20use\x20`smalloc()`\x20instead.")));
void	free(void *ptr) __attribute__
	((deprecated("you\x20may\x20use\x20`sfree()`\x20instead.")));
void	exit(int status) __attribute__
	((deprecated("you\x20may\x20use\x20`sexit()`\x20instead.")));

/*
** `malloc` and `free` wrappers to store data into
** the linked list, and `exit` wrapper to free at exit.
*/
void	*smalloc(size_t size) __attribute__((malloc));
void	sfree(void *ptr);
void	sexit(int status) __attribute__((noreturn));

/*
** Get size of allocated pointer `ptr`.
*/
size_t	sizealloc(void *ptr);

#endif
