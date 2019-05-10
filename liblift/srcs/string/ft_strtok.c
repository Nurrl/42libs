/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:04:20 by lroux             #+#    #+#             */
/*   Updated: 2019/03/16 15:43:39 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/string.h"

char	*ft_strtok(char *str, const char *sep)
{
	static char *p = 0;

	if (str)
		p = str;
	else if (!p)
		return (NULL);
	str = p + ft_strspn(p, sep);
	p = str + ft_strcspn(str, sep);
	if (p == str)
		return ((p = NULL));
	if (*p)
	{
		*p = '\0';
		++p;
	}
	else
		p = NULL;
	return (str);
}
