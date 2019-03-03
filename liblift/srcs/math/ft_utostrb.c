/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utostrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:34:35 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 21:47:38 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/math.h"
#include "lift/string.h"

#include <stdio.h>

void	ft_utostrb(char *buf, unsigned long long num,
			int base, int precision)
{
	int		index;

	index = ((precision == -1 || ft_uintlen(num, base) > precision)
		? ft_uintlen(num, base)
		: precision) - 1;
	buf[index + 1] = 0;
	while (1)
	{
		buf[index--] = BASE36[(num % base)];
		num = num / base;
		if (index < 0)
			break ;
	}
}
