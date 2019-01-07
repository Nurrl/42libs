/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:34:35 by lroux             #+#    #+#             */
/*   Updated: 2018/12/03 15:47:13 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utostr(unsigned long long num, int base)
{
	char	*fresh;
	char	*sbase;
	int		ilen;

	sbase = "0123456789abcdef";
	ilen = ft_uintlen(num, base);
	if (!(fresh = ft_strnew(ilen + 1)))
		return (NULL);
	while (1)
	{
		fresh[ilen--] = sbase[(num % base)];
		num = num / base;
		if (!num || ilen < 0)
			break ;
	}
	return (fresh);
}
