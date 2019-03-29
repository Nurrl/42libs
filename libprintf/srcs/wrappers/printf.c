/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:48:40 by lroux             #+#    #+#             */
/*   Updated: 2019/03/29 18:50:36 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libpf.intern.h"

static int	flush(char *buf, size_t size)
{
	return (write(stdout, buf, size));
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rt;

	va_start(ap, format);
	rt = ft_vprintf(format, ap);
	va_end(ap);
	return (rt);
}

int			ft_vprintf(const char *format, va_list ap)
{
	t_pf	env;
	char	buf[BUFSIZE + 1];

	env = (t_pf){0, NULL, NULL, &flush, buf, 0};
	pfstart(&env, (char*)format, ap);
	env.count += flush(env.buf, env.size);
	env.size = 0;
	return (env.count);
}
