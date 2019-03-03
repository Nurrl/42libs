/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:25:48 by lroux             #+#    #+#             */
/*   Updated: 2019/03/02 17:04:20 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

t_ret	pfhandlefloat(t_arg *arg, t_flag flag)
{
	t_ret ret;

	(void)arg;
	(void)flag;
	ft_strcpy(ret.leading, "");
	ret.str = "I'm hidden <3";
	ret.size = 0;
	return (ret);
}
