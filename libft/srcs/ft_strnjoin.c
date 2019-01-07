/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:17:50 by lroux             #+#    #+#             */
/*   Updated: 2018/11/16 12:55:24 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	char *fresh;

	if (!s1 && !s2)
		return (NULL);
	if (!(fresh = ft_strnew(ft_strlen(s1) + n)))
		return (NULL);
	ft_strcpy(fresh, s1);
	ft_strncat(fresh, s2, n);
	return (fresh);
}
