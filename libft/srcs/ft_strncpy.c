/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:33:55 by lroux             #+#    #+#             */
/*   Updated: 2018/11/06 19:41:41 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t slen;

	slen = ft_strlen(src);
	i = -1;
	while (++i < len)
	{
		if (i < slen)
			dst[i] = src[i];
		else
			dst[i] = '\0';
	}
	return (dst);
}
