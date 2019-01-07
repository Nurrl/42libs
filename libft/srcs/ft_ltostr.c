/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:34:35 by lroux             #+#    #+#             */
/*   Updated: 2018/11/12 13:00:44 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_intlen(int n)
{
	char len;

	len = 0;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_ltostr(long num, int base)
{
	char	*fresh;
	char	*sbase;
	int		index;
	t_bool	invert;
	size_t	ilen;

	sbase = "0123456789abcdef";
	invert = (num < 0) ? true : false;
	ilen = ft_intlen(num);
	index = (invert) ? ilen + 1 : ilen;
	if (!(fresh = ft_strnew(index + 1)))
		return (NULL);
	while (1)
	{
		fresh[index--] = sbase[(invert) ? -(num % base) : (num % base)];
		num = num / 10;
		if (!num)
			break ;
	}
	if (invert)
		fresh[0] = '-';
	return (invert) ? (fresh + index) : (fresh + index + 1);
}
