/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:17:57 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 16:50:56 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/memory.h"
#include "lift/types.h"
#include <stdlib.h>

void	*vmemchr(const void *s, int c, size_t n)
{
	while (n--)
		if (*((t_uint8*)s++) == (t_uint8)c)
			return ((void*)s - 1);
	return (NULL);
}
