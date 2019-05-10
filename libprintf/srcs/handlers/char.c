/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:45:43 by lroux             #+#    #+#             */
/*   Updated: 2019/03/02 16:34:52 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

t_ret		pfhandlechar(t_arg *arg, t_flag flag)
{
	t_ret	ret;

	(void)flag;
	ft_strcpy(ret.leading, "");
	ret.str = (char*)&arg->l;
	ret.size = 1;
	return (ret);
}

t_ret		pfhandlestr(t_arg *arg, t_flag flag)
{
	int		len;
	t_ret	ret;

	ft_strcpy(ret.leading, "");
	ret.size = 0;
	if (!arg->p)
		ret.str = "(null)";
	else
		ret.str = arg->p;
	len = ft_strlen(ret.str);
	if (flag.precision > -1 && flag.precision < len)
		ret.size = flag.precision;
	else
		ret.size = len;
	return (ret);
}
