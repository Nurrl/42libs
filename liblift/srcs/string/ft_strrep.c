/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:00:52 by lroux             #+#    #+#             */
/*   Updated: 2019/03/12 14:47:22 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/string.h"

char	*ft_strrep(char *s, char search, char replace)
{
	char	*start;

	start = s;
	while (*s)
	{
		if (*s == search)
			*s = replace;
		++s;
	}
	return (start);
}
