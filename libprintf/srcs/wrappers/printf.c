/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:48:40 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 19:45:53 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "libpf.intern.h"

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rt;

	va_start(ap, format);
	rt = ft_vprintf(format, ap);
	va_end(ap);
	return (rt);
}

static int	store(t_pf *env, const char *s, size_t size)
{
	(void)env;
	return (write(stdout, s, size));
}

static int	storemove(t_pf *env, char **s, size_t size)
{
	*s += size;
	return (env->store(env, *s - size, size));
}

int			ft_vprintf(const char *format, va_list ap)
{
	t_pf	env;

	env = (t_pf){0, &store, &storemove};
	pfstart(&env, (char*)format, ap);
	return (env.count);
}
