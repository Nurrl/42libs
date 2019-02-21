/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:38:03 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 16:56:55 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/char.h"

int	ft_strcw(const char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			++s;
		if (!*s)
			break ;
		while (!ft_isspace(*s) && *s)
			++s;
		count++;
	}
	return (count);
}
