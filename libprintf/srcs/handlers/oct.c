/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:40:13 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 21:36:54 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

t_ret	pfhandleoct(t_arg *arg, t_flag flag)
{
	static char	num[MAXPRECISION + 1];
	t_ret		ret;

	ft_strcpy(ret.leading, "");
	ft_utostrb(num, arg->l, 8, ft_min(MAXPRECISION, flag.precision));
	ret.str = (!arg->l && flag.precision == 0) ? "" : num;
	if (flag.flags & FLAGALTER)
		ft_strcpy(ret.leading, "0");
	ret.size = ft_strlen(ret.str);
	return (ret);
}
