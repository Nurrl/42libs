/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:25:48 by lroux             #+#    #+#             */
/*   Updated: 2019/04/02 22:30:44 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

/*
** `Infinity` => `exponent` (0xFF for 32-bit floats or 0x7FF for 64-bit doubles)
**               `mantiss`  == 0
**               `usage`    Results from an operation such as dividing by zero.
**
** `NaN` =>      `exponent` (0xFF for 32-bit floats or 0x7FF for 64-bit doubles)
**               `mantiss`  > 0
**               `usage`    NaN stands for “not a number” and they used when
**                            an operation does not equate to a real number
**                            such as taking the square root of a negative.
*/

typedef struct	s_float {
	t_bool	neg;
	t_u16	exponent;
	t_u64	mantiss;
}				t_float;

t_ret	pfhandlefloat(t_arg *arg, t_flag flag)
{
	static char	num[MAXPRECISION + 1];
	t_ret		ret;

	(void)arg;
	(void)flag;
	ft_strcpy(ret.leading, "");
	ret.str = num;
	ret.size = 0;
	return (ret);
}
