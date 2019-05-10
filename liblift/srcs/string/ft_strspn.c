/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:25:27 by lroux             #+#    #+#             */
/*   Updated: 2019/03/20 16:57:34 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/char.h"
#include "lift/string.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	char *start;

	start = (char*)s;
	while (*s)
	{
		if (!ft_inset(*s, charset))
			break ;
		++s;
	}
	return (s - start);
}
