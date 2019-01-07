/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:34:35 by lroux             #+#    #+#             */
/*   Updated: 2018/12/03 15:45:00 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itostr(long long num, int base)
{
	char	*fresh;
	char	*sbase;
	int		index;
	t_bool	invert;

	sbase = "0123456789abcdef";
	invert = (num < 0) ? true : false;
	index = ft_intlen(num, base);
	if (!(fresh = ft_strnew(index + 1)))
		return (NULL);
	while (1)
	{
		fresh[index--] = sbase[(invert) ? -(num % base) : (num % base)];
		num = num / base;
		if (!num || index < 0)
			break ;
	}
	if (invert)
		fresh[0] = '-';
	return (fresh);
}
