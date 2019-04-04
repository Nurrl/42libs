/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:18:24 by lroux             #+#    #+#             */
/*   Updated: 2019/03/15 15:19:30 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/string.h"

char	*ft_strnrep(char *s, size_t size, char search, char replace)
{
	char	*start;

	start = s;
	while (*s && size--)
	{
		if (*s == search)
			*s = replace;
		++s;
	}
	return (start);
}
