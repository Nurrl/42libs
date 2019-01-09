/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:33:16 by lroux             #+#    #+#             */
/*   Updated: 2019/01/08 17:06:54 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.intern.h"

static void	freenode(t_alist *node)
{
	free(node->address);
	free(node);
}

void		gcclean(void)
{
	listeach(&freenode);
}
