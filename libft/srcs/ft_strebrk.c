/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strebrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:30:52 by lroux             #+#    #+#             */
/*   Updated: 2018/12/30 20:13:50 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strebrk(const char *s, const char *charset)
{
	const char *sc;

	sc = charset;
	while (*s)
	{
		while (*charset)
		{
			if (*charset == *s)
				return ((char*)s);
			charset++;
		}
		charset = sc;
		++s;
	}
	return ((char*)s);
}
