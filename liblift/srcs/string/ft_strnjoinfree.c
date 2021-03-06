/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:31:32 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 17:28:33 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lift/string.h"

char	*ft_strnjoinfree(char *s1, const char *s2, size_t n)
{
	char *fresh;

	if (!s1 || !s2)
		return (NULL);
	if (!(fresh = ft_strnew(ft_strlen(s1) + n)))
		return (NULL);
	ft_strcpy(fresh, s1);
	ft_strdel(&s1);
	ft_strncat(fresh, s2, n);
	return (fresh);
}
