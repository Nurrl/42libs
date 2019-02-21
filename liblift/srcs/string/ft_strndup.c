/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:41:15 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 17:25:23 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lift/memory.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*new;

	if ((new = (char*)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	ft_memcpy(new, s1, n);
	new[n] = 0;
	return (new);
}
