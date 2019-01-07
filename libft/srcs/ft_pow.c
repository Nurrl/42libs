/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:34:25 by lroux             #+#    #+#             */
/*   Updated: 2018/12/09 15:01:00 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_pow(long long x, unsigned long long y)
{
	if (y == 0)
		return (1);
	else if (y % 2 == 0)
		return (ft_pow(x, y / 2) * ft_pow(x, y / 2));
	else
		return (x * ft_pow(x, y / 2) * ft_pow(x, y / 2));
}
