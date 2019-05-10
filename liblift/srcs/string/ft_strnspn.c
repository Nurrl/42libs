/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:40:57 by lroux             #+#    #+#             */
/*   Updated: 2019/03/20 19:43:07 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/char.h"
#include "lift/string.h"

size_t	ft_strnspn(const char *s, size_t count, const char *charset)
{
	char *start;

	start = (char*)s;
	while (*s)
	{
		if (!ft_inset(*s, charset))
			count--;
		if (!count)
			break ;
		++s;
	}
	return (s - start);
}
