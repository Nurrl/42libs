/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:17:57 by lroux             #+#    #+#             */
/*   Updated: 2019/04/02 22:27:03 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/memory.h"
#include "lift/types.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
		if (*((t_u8*)s++) == (t_u8)c)
			return ((void*)s - 1);
	return (NULL);
}
