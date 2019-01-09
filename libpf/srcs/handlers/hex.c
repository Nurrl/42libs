/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:38:53 by lroux             #+#    #+#             */
/*   Updated: 2018/12/05 14:39:24 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

void		pfhandlehex(t_arg *arg, t_flag *flag)
{
	t_uint64 nb;

	nb = arg->l;
	if (nb == 0 && flag->precision == 0)
	{
		flag->finished = ft_strdup("");
		return ;
	}
	if (nb > 0 && flag->flags & FLAGALTER)
		flag->leading = "0x";
	flag->finished = pfutostr(nb, 16, flag->precision);
}

void		pfhandlehexup(t_arg *arg, t_flag *flag)
{
	pfhandlehex(arg, flag);
	if (!flag->finished)
		return ;
	if (flag->leading)
		flag->leading = "0X";
	flag->finished = ft_strupr(flag->finished);
}
