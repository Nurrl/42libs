/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:48:40 by lroux             #+#    #+#             */
/*   Updated: 2019/04/02 23:55:55 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libpf.intern.h"

static int	g_fd = -1;

static int	flush(char *buf, size_t size)
{
	return (write(g_fd, buf, size));
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		rt;

	va_start(ap, format);
	rt = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (rt);
}

int			ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_pf	env;
	char	buf[BUFSIZE + 1];

	g_fd = fd;
	env = (t_pf){0, &flush, buf, 0};
	pfstart(&env, (char*)format, ap);
	if (env.count > -1 && env.size > 0)
		env.count += flush(env.buf, env.size);
	else if (env.count < 0)
		env.count = -1;
	env.size = 0;
	return (env.count);
}
