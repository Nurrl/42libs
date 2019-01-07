/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:29:45 by lroux             #+#    #+#             */
/*   Updated: 2018/11/12 12:17:02 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char *end;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		++s;
	if (!*s)
		return (ft_strdup(""));
	end = (char*)(s + ft_strlen(s) - 1);
	while (*end == ' ' || *end == '\n' || *end == '\t')
		end--;
	return (ft_strndup(s, end - s + 1));
}
