/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:34:40 by lroux             #+#    #+#             */
/*   Updated: 2019/01/09 19:02:54 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

int				ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int		count;
	int		len;
	t_flag	flag;

	count = 0;
	if (!ret || !(*ret = ft_strnew(0)))
		return (-1);
	while (*format)
	{
		if (*format == '{')
			pfappend(ret, &count, *pfsubstr((char**)&format, &flag), false);
		else if (*format == '%')
			pfappend(ret, &count, *pflexer((char**)&format, ap, &flag), true);
		else
		{
			len = ft_strebrk(format, "{%") - format;
			pfappend(ret, &count, (t_flag)
					{ .len = len, .finished = ft_strndup(format, len) }, true);
			format += len;
		}
		if (!*ret || !*format)
			break ;
	}
	return (count);
}

static void		pfpadleft(t_flag *flag, int pad, char *new)
{
	ft_memset(new,
		((flag->flags & FLAGZERO) && flag->precision < 1) ? '0' : ' ', pad);
	ft_memcpy(new + pad, flag->finished, flag->len);
	if (flag->leading && (flag->flags & FLAGZERO))
		ft_memcpy(new, flag->leading, ft_strlen(flag->leading));
	else if (flag->leading && !(flag->flags & FLAGZERO))
		ft_memcpy(new + pad - ft_strlen(flag->leading), flag->leading,
			ft_strlen(flag->leading));
}

static void		pfpad(t_flag *flag)
{
	int		pad;
	char	*new;

	if (flag->leading && (flag->flags & FLAGMINUS))
	{
		pfprepend(flag->leading, &flag->finished, false);
		flag->len += ft_strlen(flag->leading);
	}
	pad = flag->width - flag->len;
	if (!(new = ft_calloc(flag->len + pad + 2, sizeof(char*))))
		return ;
	if (flag->flags & FLAGMINUS)
	{
		ft_memcpy(new, flag->finished, flag->len);
		ft_memset(new + flag->len,
			(flag->flags & FLAGZERO && flag->precision == -1) ? '0' : ' ', pad);
	}
	else
		pfpadleft(flag, pad, new);
	free(flag->finished);
	flag->len += pad;
	flag->finished = new;
}

static t_flag	*pfuse(t_flag *flag, va_list ap)
{
	if (pfcall(flag, ap) == -1)
		flag->finished = ft_strndup(&flag->type, 1);
	if (flag->len == -1)
		flag->len = ft_strlen((flag->finished) ? flag->finished : "");
	if (flag->width <= flag->len)
	{
		if (flag->leading)
		{
			pfprepend(flag->leading, &flag->finished, false);
			flag->len += ft_strlen(flag->leading);
		}
		return (flag);
	}
	pfpad(flag);
	return (flag);
}

t_flag			*pflexer(char **format, va_list ap, t_flag *flag)
{
	(*format)++;
	flag->leading = 0;
	flag->finished = 0;
	flag->len = -1;
	pflexparam(flag, format);
	pflexflags(flag, format);
	pflexwidth(flag, format, ap);
	pflexprecision(flag, format, ap);
	if (pflexlandt(flag, format) == PF_ERR)
		return (flag);
	return (pfuse(flag, ap));
}
