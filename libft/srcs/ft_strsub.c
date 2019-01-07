/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:06:45 by lroux             #+#    #+#             */
/*   Updated: 2018/11/12 12:14:47 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *fresh;

	if (!s)
		return (NULL);
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	ft_strncpy(fresh, (s + start), len);
	return (fresh);
}
