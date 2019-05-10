/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:46:07 by lroux             #+#    #+#             */
/*   Updated: 2019/03/20 20:03:43 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/char.h"
#include "lift/string.h"

size_t	ft_strncspn(const char *s, size_t count, const char *charset)
{
	char *start;

	start = (char*)s;
	while (*s)
	{
		if (ft_inset(*s, charset))
			count--;
		if (!count)
			break ;
		++s;
	}
	return (s - start);
}
