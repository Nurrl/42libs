/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:48:06 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 21:37:12 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

t_ret		pfhandleptr(t_arg *arg, t_flag flag)
{
	static char	num[MAXPRECISION + 1];
	t_ret		ret;

	ft_strcpy(ret.leading, "0x");
	ft_utostrb(num, arg->l, 16, ft_min(MAXPRECISION, flag.precision));
	ret.str = (!arg->p && flag.precision == 0) ? "" : num;
	ret.size = ft_strlen(ret.str);
	return (ret);
}
