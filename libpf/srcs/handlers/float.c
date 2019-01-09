/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:25:48 by lroux             #+#    #+#             */
/*   Updated: 2018/12/05 14:48:42 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

void		pfhandlefloat(t_arg *arg, t_flag *flag)
{
	flag->precision = (flag->precision == -1) ? 6 : flag->precision;
	flag->finished = pfdtostr(arg->f,
			flag->precision, (flag->flags & FLAGALTER) ? 1 : 0);
}
