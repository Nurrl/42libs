/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:49:54 by lroux             #+#    #+#             */
/*   Updated: 2018/11/12 12:07:09 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		n;
	char	*fresh;

	n = (s) ? ft_strlen(s) : 0;
	if (!(fresh = ft_strnew(n)))
		return (NULL);
	while (n--)
		fresh[n] = f(*(s + n));
	return (fresh);
}
