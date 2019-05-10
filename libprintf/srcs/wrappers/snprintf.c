/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:48:40 by lroux             #+#    #+#             */
/*   Updated: 2019/04/30 18:50:22 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "libpf.intern.h"

static char		*g_str = NULL;
static size_t	g_size = 0;
static size_t	g_count = 0;

static int		flush(char *buf, size_t size)
{
	size_t			wc;

	if (size + g_count > g_size - 1)
		wc = (g_size - 1) - g_count;
	else
		wc = size;
	if (!g_size)
		return (size);
	if (!g_str)
		return (-1);
	ft_memcpy(g_str + g_count, buf, wc);
	g_count += wc;
	g_str[g_count] = '\0';
	return (size);
}

int				ft_snprintf(char *str,
					size_t size, const char *format, ...)
{
	va_list	ap;
	int		rt;

	va_start(ap, format);
	rt = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (rt);
}

int				ft_vsnprintf(char *str,
					size_t size, const char *format, va_list ap)
{
	t_pf	env;
	char	buf[BUFSIZE + 1];

	g_str = str;
	g_size = size;
	g_count = 0;
	env = (t_pf){0, &flush, buf, 0};
	pfstart(&env, (char*)format, ap);
	if (env.count > -1 && env.size > 0)
		env.count += flush(env.buf, env.size);
	else if (env.count < 0)
		env.count = -1;
	env.size = 0;
	return (env.count);
}
