/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:48:40 by lroux             #+#    #+#             */
/*   Updated: 2018/12/05 17:22:03 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
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
	char	*ret;
	int		len;

	len = ft_vasprintf(&ret, format, ap);
	write(fd, ret, len);
	if (ret)
		free(ret);
	return (len);
}

int			ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		rt;

	va_start(ap, format);
	rt = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (rt);
}
