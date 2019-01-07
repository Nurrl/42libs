/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:34:14 by lroux             #+#    #+#             */
/*   Updated: 2018/11/16 17:28:44 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, const char *s2)
{
	char *fresh;

	if (!s1 || !s2)
		return (NULL);
	if (!(fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(fresh, s1);
	ft_strdel(&s1);
	ft_strcat(fresh, s2);
	return (fresh);
}
