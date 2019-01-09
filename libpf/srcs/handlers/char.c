/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:45:43 by lroux             #+#    #+#             */
/*   Updated: 2018/12/07 17:34:08 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

void		pfhandlechar(t_arg *arg, t_flag *flag)
{
	flag->finished = ft_strndup((const char*)&arg->l, 1);
	flag->len = 1;
}

void		pfhandlestr(t_arg *arg, t_flag *flag)
{
	if (!arg->p)
	{
		flag->finished = ft_strdup((flag->precision != -1) ? "" : "(null)");
		return ;
	}
	if (flag->precision > -1)
	{
		flag->finished = ft_strndup(arg->p, flag->precision);
		if (flag->precision < (int)ft_strlen(arg->p)
				&& flag->flags & FLAGALTER)
			flag->finished = ft_strjoinfree(flag->finished, "..");
		return ;
	}
	flag->finished = ft_strdup(arg->p);
}
