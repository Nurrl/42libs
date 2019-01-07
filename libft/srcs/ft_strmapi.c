/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:56:12 by lroux             #+#    #+#             */
/*   Updated: 2018/11/12 12:09:04 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		n;
	char	*fresh;

	n = (s) ? ft_strlen(s) : 0;
	if (!(fresh = ft_strnew(n)))
		return (NULL);
	while (n--)
		fresh[n] = f(n, *(s + n));
	return (fresh);
}
