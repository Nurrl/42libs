/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:58:30 by lroux             #+#    #+#             */
/*   Updated: 2019/04/01 19:41:59 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

static t_bool	pflexer(t_flag *flag, char **format, va_list ap)
{
	(*format)++;
	pflexparam(flag, format);
	pflexflags(flag, format);
	pflexwidth(flag, format, ap);
	pflexprecision(flag, format, ap);
	return (pflexlandt(flag, format));
}

static void		pfpad(t_pf *env, size_t size, char c)
{
	char pad[256];

	if (size == 0)
		return ;
	ft_memset(pad, c, (size > sizeof(pad)) ? sizeof(pad) : size);
	while (size >= sizeof(pad))
	{
		pfstore(env, pad, sizeof(pad));
		size -= sizeof(pad);
	}
	pfstore(env, pad, size);
}

void			pfflaglen(t_flag *flag, char *dum, char **format)
{
	if (dum == *format)
		flag->length = BARE;
	else if (dum[0] == 'l' && dum[1] == 'l')
		flag->length = LLPRE;
	else if (dum[0] == 'h' && dum[1] == 'h')
		flag->length = HHPRE;
	else if (dum[0] == 'l')
		flag->length = LPRE;
	else if (dum[0] == 'h')
		flag->length = HPRE;
	else if (dum[0] == 'L')
		flag->length = BLPRE;
	else if (dum[0] == 'z' || dum[0] == 't')
		flag->length = ZPRE;
	else if (dum[0] == 'j')
		flag->length = JPRE;
	else
		flag->length = BARE;
}

void			pfflag(t_pf *env, char **format, va_list ap)
{
	t_flag	flag;
	t_arg	arg;
	t_ret	ret;
	t_bool	dopad;

	if (pflexer(&flag, format, ap))
		ret = pfcall(flag, &arg, ap);
	else if (!**format)
		return ;
	else
		ret = (t_ret){{0, 0, 0}, *format, 1};
	if (flag.flags & FLAGZERO)
		pfstore(env, ret.leading, ft_strlen(ret.leading));
	dopad = (flag.width != -1 && flag.width
				> (int)(ret.size + ft_strlen(ret.leading)));
	if (dopad && !(flag.flags & FLAGMINUS))
		pfpad(env, flag.width - (ret.size + ft_strlen(ret.leading)),
				(flag.flags & FLAGZERO && flag.precision == -1) ? '0' : ' ');
	if (!(flag.flags & FLAGZERO))
		pfstore(env, ret.leading, ft_strlen(ret.leading));
	pfstore(env, ret.str, ret.size);
	if (dopad && (flag.flags & FLAGMINUS))
		pfpad(env, flag.width - (int)(ret.size + ft_strlen(ret.leading)),
				(flag.flags & FLAGZERO && flag.precision == -1) ? '0' : ' ');
	(*format)++;
}
