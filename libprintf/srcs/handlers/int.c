/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:42:49 by lroux             #+#    #+#             */
/*   Updated: 2018/12/05 14:44:50 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

void		pfhandleint(t_arg *arg, t_flag *flag)
{
	flag->finished = pfitostr(arg->l, 10, flag);
}

void		pfhandleuint(t_arg *arg, t_flag *flag)
{
	t_uint64 nb;

	nb = arg->l;
	if (nb == 0 && flag->precision == 0)
	{
		flag->finished = ft_strdup("");
		return ;
	}
	flag->finished = pfutostr(nb, 10, flag->precision);
}
