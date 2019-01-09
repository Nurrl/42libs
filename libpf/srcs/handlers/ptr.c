/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:48:06 by lroux             #+#    #+#             */
/*   Updated: 2018/12/05 14:48:25 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

void		pfhandleptr(t_arg *arg, t_flag *flag)
{
	char *num;

	if (!arg->l && flag->precision == 0)
	{
		flag->finished = ft_strdup("0x");
		return ;
	}
	if (!(num = pfutostr(arg->l, 16, flag->precision)))
		return ;
	pfprepend("0x", &num, false);
	flag->finished = num;
}
