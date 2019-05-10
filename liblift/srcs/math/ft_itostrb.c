/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:34:35 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 22:05:36 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/math.h"
#include "lift/types.h"
#include "lift/string.h"

#include <stdio.h>

void	ft_itostrb(char *buf, long long num, int base, int precision)
{
	int		index;
	t_bool	invert;

	invert = (num < 0) ? true : false;
	index = ((precision == -1 || ft_intlen(num, base) > precision)
		? ft_intlen(num, base)
		: precision) - 1;
	if (precision != -1)
		index += invert;
	buf[index + 1] = 0;
	while (1)
	{
		buf[index--] = BASE36[(invert) ? -(num % base) : (num % base)];
		num = num / base;
		if (index < (int)invert)
			break ;
	}
	if (invert)
		buf[0] = '-';
}
