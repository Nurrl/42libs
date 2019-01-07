/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:13:38 by lroux             #+#    #+#             */
/*   Updated: 2018/11/13 13:47:47 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void			ft_bzero(void *s, size_t n)
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
