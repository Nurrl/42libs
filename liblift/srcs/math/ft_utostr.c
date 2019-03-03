/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:34:35 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 21:39:58 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/math.h"
#include "lift/string.h"

char	*ft_utostr(unsigned long long num, int base)
{
	char	*fresh;
	int		index;

	index = ft_uintlen(num, base) - 1;
	if (!(fresh = ft_strnew(index + 1)))
		return (NULL);
	while (1)
	{
		fresh[index--] = BASE36[(num % base)];
		num = num / base;
		if (!num || index < 0)
			break ;
	}
	return (fresh);
}
