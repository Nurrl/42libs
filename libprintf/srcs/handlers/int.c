/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:42:49 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 21:35:59 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

t_ret	pfhandleint(t_arg *arg, t_flag flag)
{
	static char	num[MAXPRECISION + 1];
	t_ret		ret;

	ft_strcpy(ret.leading, "");
	ft_itostrb(num, arg->l, 10, ft_min(MAXPRECISION, flag.precision));
	ret.str = (!arg->l && flag.precision == 0) ? "" : num;
	if ((long long)arg->l < 0)
	{
		ret.str++;
		ft_strcpy(ret.leading, "-");
	}
	else if (flag.flags & FLAGBLANK)
		ft_strcpy(ret.leading, " ");
	else if (flag.flags & FLAGPLUS)
		ft_strcpy(ret.leading, "+");
	ret.size = ft_strlen(ret.str);
	return (ret);
}

t_ret	pfhandleuint(t_arg *arg, t_flag flag)
{
	static char	num[MAXPRECISION + 1];
	t_ret		ret;

	ft_strcpy(ret.leading, "");
	ft_utostrb(num, arg->l, 10, ft_min(MAXPRECISION, flag.precision));
	ret.str = (!arg->l && flag.precision == 0) ? "" : num;
	ret.size = ft_strlen(ret.str);
	return (ret);
}
