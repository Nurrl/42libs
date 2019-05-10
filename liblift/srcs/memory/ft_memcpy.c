/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:15:54 by lroux             #+#    #+#             */
/*   Updated: 2019/04/02 22:27:51 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/memory.h"
#include "lift/types.h"
#include <stdlib.h>

static size_t	memcpy1b(void **dst, const void **src)
{
	*((t_u8*)*dst) = *((t_u8*)*src);
	*dst += 1;
	*src += 1;
	return (1);
}

static size_t	memcpy2b(void **dst, const void **src)
{
	*((t_u16*)*dst) = *((t_u16*)*src);
	*dst += 2;
	*src += 2;
	return (2);
}

static size_t	memcpy4b(void **dst, const void **src)
{
	*((t_u32*)*dst) = *((t_u32*)*src);
	*dst += 4;
	*src += 4;
	return (4);
}

static size_t	memcpy8b(void **dst, const void **src)
{
	*((t_u64*)*dst) = *((t_u64*)*src);
	*dst += 8;
	*src += 8;
	return (8);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *init;

	init = dst;
	while (n)
	{
		if (n < 2)
			n -= memcpy1b(&dst, &src);
		else if (n < 4)
			n -= memcpy2b(&dst, &src);
		else if (n < 8)
			n -= memcpy4b(&dst, &src);
		else
			n -= memcpy8b(&dst, &src);
	}
	return (init);
}
