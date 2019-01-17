/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:38:03 by lroux             #+#    #+#             */
/*   Updated: 2019/01/15 14:51:48 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cw(const char *s)
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
