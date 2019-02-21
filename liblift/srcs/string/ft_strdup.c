/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:18:03 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 17:04:23 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/string.h"
#include "lift/memory.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		len;

	len = ft_strlen(s1) + 1;
	if ((new = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	ft_memcpy(new, s1, len);
	return (new);
}
