/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:01:45 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 16:34:02 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/types.h"
#include "lift/char.h"

int		ft_atoi(const char *str)
{
	t_uint64	num;
	t_bool		negative;

	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == '\n')
		++str;
	negative = (*str == '-') ? true : false;
	if (*str == '+' || negative)
		str++;
	if (!ft_isdigit(*str))
		return (0);
	num = 0;
	while (ft_isdigit(*str))
		num = num * 10 + *(str++) - '0';
	return ((negative) ? -num : num);
}