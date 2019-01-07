/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strebrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:30:52 by lroux             #+#    #+#             */
/*   Updated: 2018/12/07 14:36:21 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strebrk(const char *s, const char *charset)
{
	char *pos;

	while (*charset)
		if ((pos = ft_strchr(s, *charset++)))
			return (pos);
	return ((char*)s + ft_strlen(s));
}
