/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:45:07 by lroux             #+#    #+#             */
/*   Updated: 2019/04/04 15:31:20 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

void	pfstore(t_pf *env, const char *s, size_t size)
{
	size_t len;

	if (env->size + size > BUFSIZE)
	{
		len = (env->size + size) - BUFSIZE;
		pfstore(env, s, size - len);
		env->count += env->flush(env->buf, env->size);
		env->size = 0;
		pfstore(env, s + (size - len), len);
	}
	else
	{
		ft_memcpy(env->buf + env->size, s, size);
		env->size += size;
	}
}

void	pfstoremove(t_pf *env, char **s, size_t size)
{
	*s += size;
	pfstore(env, *s - size, size);
}

void	pfstart(t_pf *env, char *format, va_list ap)
{
	if (!format)
		env->count = -1;
	while (*format && env->count != -1)
	{
		if (*format == '{')
			pfspecial(env, &format, ap);
		else if (*format == '%')
			pfflag(env, &format, ap);
		else
			pfstoremove(env, &format,
					ft_strebrk(format, "{%") - format);
	}
}
