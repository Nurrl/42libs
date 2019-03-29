/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:45:07 by lroux             #+#    #+#             */
/*   Updated: 2019/03/29 18:49:22 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

static void	store(t_pf *env, const char *s, size_t size)
{
	size_t len;

	if (env->size + size > BUFSIZE)
	{
		len = (env->size + size) - BUFSIZE;
		store(env, s, len);
		env->count += env->flush(env->buf, env->size);
		env->size = 0;
		store(env, s + len, size - len);
	}
	else
	{
		ft_memcpy(env->buf + env->size, s, size);
		env->size += size;
	}
}

static void	storemove(t_pf *env, char **s, size_t size)
{
	*s += size;
	env->store(env, *s - size, size);
}

void		pfstart(t_pf *env, char *format, va_list ap)
{
	env->store = &store;
	env->storemove = &storemove;
	while (*format)
	{
		if (*format == '{')
			pfspecial(env, &format, ap);
		else if (*format == '%')
			pfflag(env, &format, ap);
		else
			env->storemove(env, &format,
					ft_strebrk(format, "{%") - format);
	}
}
