/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:05:11 by lroux             #+#    #+#             */
/*   Updated: 2018/11/13 12:33:18 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LOMAGIC32 0x01010101L
#define HIMAGIC32 0x80808080L

#define LOMAGIC64 0x0101010101010101L
#define HIMAGIC64 0x8080808080808080L

static size_t	ft_retlen(const char *partc, const char *s)
{
	if (partc[0] == 0)
		return (partc - s);
	if (partc[1] == 0)
		return (partc - s + 1);
	if (partc[2] == 0)
		return (partc - s + 2);
	if (partc[3] == 0)
		return (partc - s + 3);
	if (sizeof(unsigned int) == 8)
	{
		if (partc[4] == 0)
			return (partc - s + 4);
		if (partc[5] == 0)
			return (partc - s + 5);
		if (partc[6] == 0)
			return (partc - s + 6);
		if (partc[7] == 0)
			return (partc - s + 7);
	}
	return (0);
}

size_t			ft_strlen(const char *s)
{
	const char		*sptr;
	unsigned int	*partp;
	unsigned int	part;

	sptr = s;
	while (((unsigned long)sptr & (sizeof(unsigned int) - 1)) != 0)
		if (!*sptr++)
			return (sptr - s - 1);
	partp = (unsigned int*)sptr;
	while (1)
	{
		part = *partp++;
		if (((part - ((sizeof(unsigned int) == 8) ? LOMAGIC64 : LOMAGIC32))
		& ~part & (((sizeof(unsigned int) == 8) ? HIMAGIC64 : HIMAGIC32))) != 0)
			return (ft_retlen((const char*)(partp - 1), s));
	}
	return (0);
}
