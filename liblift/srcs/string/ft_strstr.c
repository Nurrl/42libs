/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:34:27 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 17:34:54 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/string.h"
#include "lift/memory.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *last;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		last = ft_memchr(haystack, *needle, ft_strlen(haystack));
		if (last && ft_memcmp(last, needle, ft_strlen(needle)) == 0)
			return (last);
		++haystack;
	}
	return (NULL);
}
