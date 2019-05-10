/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:38:53 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 21:36:44 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

t_ret	pfhandlehex(t_arg *arg, t_flag flag)
{
	static char	num[MAXPRECISION + 1];
	t_ret		ret;

	ft_strcpy(ret.leading, "");
	ft_utostrb(num, arg->l, 16, ft_min(MAXPRECISION, flag.precision));
	ret.str = (!arg->l && flag.precision == 0) ? "" : num;
	if (arg->l && flag.flags & FLAGALTER)
		ft_strcpy(ret.leading, "0x");
	ret.size = ft_strlen(ret.str);
	return (ret);
}

t_ret	pfhandlehexup(t_arg *arg, t_flag flag)
{
	static char	num[MAXPRECISION + 1];
	t_ret		ret;

	ft_strcpy(ret.leading, "");
	ft_utostrb(num, arg->l, 16, ft_min(MAXPRECISION, flag.precision));
	ret.str = (!arg->l && flag.precision == 0) ? "" : ft_strupr(num);
	if (arg->l && flag.flags & FLAGALTER)
		ft_strcpy(ret.leading, "0X");
	ret.size = ft_strlen(ret.str);
	return (ret);
}
