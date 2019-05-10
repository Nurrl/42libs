/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:25:48 by lroux             #+#    #+#             */
/*   Updated: 2019/04/24 18:14:35 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

/*
** `Infinity` => `exponent` (0xFF for 32-bit floats or 0x7FF for 64-bit doubles
**                           or 0x7FFF for 80-bit long doubles)
**               `mantiss`  == 0
**               `usage`    Results from an operation such as dividing by zero.
**
** `NaN` =>      `exponent` (0xFF for 32-bit floats or 0x7FF for 64-bit doubles
**                           or 0x7FFF for 80-bit long doubles)
**               `mantiss`  > 0
**               `usage`    NaN stands for “not a number” and they used when
**                            an operation does not equate to a real number
**                            such as taking the square root of a negative.
**
** Cool references:
** - http://weitz.de/ieee/
** - https://en.wikipedia.org/wiki/Extended_precision
** - https://www.geeksforgeeks.org/bit-fields-c/
*/

#include <stdio.h>
t_ret	pfhandlefloat(t_arg *arg, t_flag flag)
{
	static char	num[MAXPRECISION + 1];
	t_ret		ret;
	t_float		*flot;

	flot = (t_float*)&arg->f;
	ft_strcpy(ret.leading, "");
	ret.str = NULL;
	if (flot->sign)
		ft_strcpy(ret.leading, "-");
	if (flot->exp == 0x7FFF && flot->frac == 0)
		ret.str = "inf";
	if (flot->exp == 0x7FFF && flot->frac > 0)
		ret.str = "nan";
	if (flag.precision == -1)
		flag.precision = 6;
	/* Line of touch */
	if (!ret.str)
		; // Do process
	if (!ret.str)
		ret.str = num;
	ret.size = ft_strlen(ret.str);
	return (ret);
}
