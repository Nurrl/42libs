/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:27:06 by lroux             #+#    #+#             */
/*   Updated: 2019/04/02 22:27:29 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/memory.h"
#include "lift/types.h"
#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
		if (*(t_u8*)s1++ != *(t_u8*)s2++)
			return (*(t_u8*)(s1 - 1) - *(t_u8*)(s2 - 1));
	return (0);
}
