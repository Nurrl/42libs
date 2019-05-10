/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:48:40 by lroux             #+#    #+#             */
/*   Updated: 2019/04/02 00:10:52 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "libpf.intern.h"

static int	g_sockd = -1;
static int	g_flags = 0;

static int	flush(char *buf, size_t size)
{
	return (send(g_sockd, buf, size, g_flags));
}

int			ft_sdprintf(int sockd, int flags, const char *format, ...)
{
	va_list	ap;
	int		rt;

	va_start(ap, format);
	rt = ft_vsdprintf(sockd, flags, format, ap);
	va_end(ap);
	return (rt);
}

int			ft_vsdprintf(int sockd, int flags, const char *format, va_list ap)
{
	t_pf	env;
	char	buf[BUFSIZE + 1];

	g_sockd = sockd;
	g_flags = flags;
	env = (t_pf){0, &flush, buf, 0};
	pfstart(&env, (char*)format, ap);
	if (env.count > -1 && env.size > 0)
		env.count += flush(env.buf, env.size);
	else if (env.count < 0)
		env.count = -1;
	env.size = 0;
	return (env.count);
}
