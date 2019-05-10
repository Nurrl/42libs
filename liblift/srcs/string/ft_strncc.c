/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:21:00 by lroux             #+#    #+#             */
/*   Updated: 2019/03/20 19:23:58 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/string.h"

int	ft_strncc(const char *s, size_t size, char c)
{
	int count;

	if (!s)
		return (0);
	count = 0;
	while (*s && size--)
		if (*s++ == c)
			count++;
	return (count);
}
