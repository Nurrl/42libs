/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:40:13 by lroux             #+#    #+#             */
/*   Updated: 2019/01/17 14:37:23 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

void		pfhandleoct(t_arg *arg, t_flag *flag)
{
	t_uint64	nb;

	nb = arg->l;
	if (nb > 0 && flag->flags & FLAGALTER)
		flag->precision = (flag->precision < ft_uintlen(nb, 8) + 1)
			? ft_uintlen(nb, 8) + 1 : flag->precision;
	if (nb == 0 && flag->precision == 0 && !(flag->flags & FLAGALTER))
	{
		flag->finished = ft_strdup("");
		return ;
	}
	flag->finished = pfutostr(nb, 8, flag->precision);
}
