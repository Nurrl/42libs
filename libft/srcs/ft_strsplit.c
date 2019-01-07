/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:04:35 by lroux             #+#    #+#             */
/*   Updated: 2018/11/12 12:25:34 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcw(const char *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		index;
	int		len;

	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc((ft_strcw(s, c) + 1) * sizeof(char*))))
		return (NULL);
	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		tab[index++] = ft_strndup(s, len);
		s += len;
	}
	tab[index] = 0;
	return (tab);
}
