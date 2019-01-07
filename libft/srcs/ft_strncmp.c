/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:57:49 by lroux             #+#    #+#             */
/*   Updated: 2018/11/13 15:36:22 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	s1len;
	size_t	s2len;
	size_t	maxcmp;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len == 0 || s2len == 0)
		return (ft_memcmp(s1, s2, 1));
	if (s1len != s2len)
		maxcmp = ((s1len < s2len) ? s1len : s2len) + 1;
	else
		maxcmp = s1len;
	return (ft_memcmp(s1, s2, ((maxcmp < len) ? maxcmp : len)));
}
