/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:41:15 by lroux             #+#    #+#             */
/*   Updated: 2018/11/08 17:22:04 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*new;

	if ((new = (char*)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	ft_memcpy(new, s1, n);
	new[n] = 0;
	return (new);
}
