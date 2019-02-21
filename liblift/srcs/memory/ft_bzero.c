/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:13:38 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 16:46:01 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/types.h"
#include "lift/memory.h"
#include <stdlib.h>

static size_t	bzero1b(void **dst)
{
	*((t_uint8*)*dst) = 0;
	*dst += 1;
	return (1);
}

static size_t	bzero2b(void **dst)
{
	*((t_uint16*)*dst) = 0;
	*dst += 2;
	return (2);
}

static size_t	bzero4b(void **dst)
{
	*((t_uint32*)*dst) = 0;
	*dst += 4;
	return (4);
}

static size_t	bzero8b(void **dst)
{
	*((t_uint64*)*dst) = 0;
	*dst += 8;
	return (8);
}

void			vbzero(void *s, size_t n)
{
	while (n)
	{
		if (n < 2)
			n -= bzero1b(&s);
		else if (n < 4)
			n -= bzero2b(&s);
		else if (n < 8)
			n -= bzero4b(&s);
		else
			n -= bzero8b(&s);
	}
}
