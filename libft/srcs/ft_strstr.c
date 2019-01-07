/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:34:27 by lroux             #+#    #+#             */
/*   Updated: 2018/11/10 13:30:40 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
