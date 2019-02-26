/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:41:51 by lroux             #+#    #+#             */
/*   Updated: 2018/12/05 17:02:02 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

void		pfhandlebin(t_arg *arg, t_flag *flag)
{
	t_uint64	nb;

	nb = arg->l;
	if (flag->flags & FLAGALTER)
		flag->leading = "0b";
	flag->finished = pfutostr(nb, 2, flag->precision);
}

void		pfhandlenonprint(t_arg *arg, t_flag *flag)
{
	char	*str;
	int		i;
	int		j;

	str = arg->p;
	if (!(flag->finished = ft_calloc(2 * ft_strlen(str) + 1, sizeof(char*))))
		return ;
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (ft_isprint(str[i]))
			flag->finished[++j] = str[i];
		else
		{
			flag->finished[++j] = (str[i] != 0x0a) ? '^' : '$';
			if (str[i] != 0x0a)
				flag->finished[++j] = (str[i] != 0x7f) ? str[i] + '@' : '?';
			else
				flag->finished[++j] = '\n';
		}
	}
}
