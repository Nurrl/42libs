/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:55:28 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 17:21:28 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lift/memory.h"
#include "lift/string.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1len;

	s1len = ft_strlen(s1);
	if (!ft_memccpy(s1 + s1len, s2, 0, n))
		s1[s1len + n] = 0;
	return (s1);
}
