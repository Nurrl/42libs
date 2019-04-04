/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:48:40 by lroux             #+#    #+#             */
/*   Updated: 2019/04/02 23:56:30 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

int			ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		rt;

	va_start(ap, format);
	rt = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (rt);
}

int			ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int		size;
	va_list	nap;

	if (!ret)
		return (-1);
	va_copy(nap, ap);
	if ((size = ft_vsnprintf(NULL, 0, format, nap)) == -1)
		return (-1);
	if (!(*ret = malloc(size + 1)))
		return (-1);
	if ((size = ft_vsnprintf(*ret, size + 1, format, ap)) == -1)
		return (-1);
	return (size);
}
