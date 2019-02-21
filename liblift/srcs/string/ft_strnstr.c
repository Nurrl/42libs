/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:47:59 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 17:31:07 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lift/memory.h"
#include "lift/string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*last;
	size_t	nlen;

	if (!*needle)
		return ((char*)haystack);
	nlen = ft_strlen(needle);
	while (*haystack)
	{
		last = ft_memchr(haystack, *needle, ft_strlen(haystack));
		if (last && (size_t)(last - haystack + nlen) > len)
			break ;
		if (last && ft_memcmp(last, needle, nlen) == 0)
			return (last);
		++haystack;
		len--;
	}
	return (NULL);
}
