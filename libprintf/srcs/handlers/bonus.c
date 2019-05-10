/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:41:51 by lroux             #+#    #+#             */
/*   Updated: 2019/04/01 22:33:44 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libpf.intern.h"

t_ret	pfhandlebin(t_arg *arg, t_flag flag)
{
	static char	num[MAXPRECISION + 1];
	t_ret		ret;

	ft_strcpy(ret.leading, "");
	ft_utostrb(num, arg->l, 2, ft_min(MAXPRECISION, flag.precision));
	ret.str = num;
	if (flag.flags & FLAGALTER)
		ft_strcpy(ret.leading, "0b");
	ret.size = ft_strlen(ret.str);
	return (ret);
}

t_ret	pfhandleserr(t_arg *arg, t_flag flag)
{
	t_ret	ret;

	(void)flag;
	ft_strcpy(ret.leading, "");
	ret.str = strerror(arg->l);
	ret.size = ft_strlen(ret.str);
	return (ret);
}
