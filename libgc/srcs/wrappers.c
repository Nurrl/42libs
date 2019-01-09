/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 20:11:04 by lroux             #+#    #+#             */
/*   Updated: 2019/01/08 17:24:33 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.intern.h"

int		main(int ac, char **av)
{
	int r;

	r = smain(ac, av);
	gcclean();
	return (r);
}

void	sexit(int status)
{
	gcclean();
	exit(status);
}
