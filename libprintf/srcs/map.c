/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:18:44 by lroux             #+#    #+#             */
/*   Updated: 2018/12/05 17:02:42 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

#define BARE  0
#define LPRE  1
#define LLPRE 2
#define HPRE  3
#define HHPRE 4
#define BLPRE 5
#define ZPRE  6
#define JPRE  7
#define MAX   8

/*
** I - Handlers
** Offset: -'@'.
*/
static t_handler g_handlers['z' - '@' + 1] = {
	[('d' - '@')] = &pfhandleint,
	[('i' - '@')] = &pfhandleint,
	[('o' - '@')] = &pfhandleoct,
	[('u' - '@')] = &pfhandleuint,
	[('x' - '@')] = &pfhandlehex,
	[('X' - '@')] = &pfhandlehexup,
	[('f' - '@')] = &pfhandlefloat,
	[('c' - '@')] = &pfhandlechar,
	[('s' - '@')] = &pfhandlestr,
	[('p' - '@')] = &pfhandleptr,

	[('b' - '@')] = &pfhandlebin,
	[('r' - '@')] = &pfhandlenonprint,
};

/*
** II - Getters
*/
static unsigned char	g_types[MAX]['z' - '@' + 1] = {
	{
		[('d' - '@')] = INT,
		[('i' - '@')] = INT,
		[('o' - '@')] = UINT,
		[('u' - '@')] = UINT,
		[('x' - '@')] = UINT,
		[('X' - '@')] = UINT,
		[('f' - '@')] = DBL,
		[('c' - '@')] = CHAR,
		[('s' - '@')] = PTR,
		[('p' - '@')] = UIPTR,

		[('b' - '@')] = UINT,
		[('r' - '@')] = PTR,
	},
/*
** 1: l-prefixed
*/
	{
		[('d' - '@')] = LONG,
		[('i' - '@')] = LONG,
		[('o' - '@')] = ULONG,
		[('u' - '@')] = ULONG,
		[('x' - '@')] = ULONG,
		[('X' - '@')] = ULONG,
		[('f' - '@')] = DBL,
		[('c' - '@')] = INT,
		[('s' - '@')] = PTR,

		[('b' - '@')] = ULONG,
		[('r' - '@')] = PTR,
	},
/*
** 2: ll-prefixed
*/
	{
		[('d' - '@')] = LLONG,
		[('i' - '@')] = LLONG,
		[('o' - '@')] = ULLONG,
		[('u' - '@')] = ULLONG,
		[('x' - '@')] = ULLONG,
		[('X' - '@')] = ULLONG,

		[('b' - '@')] = ULLONG,
	},
/*
** 3: h-prefixed
*/
	{
		[('d' - '@')] = SHORT,
		[('i' - '@')] = SHORT,
		[('o' - '@')] = USHORT,
		[('u' - '@')] = USHORT,
		[('x' - '@')] = USHORT,
		[('X' - '@')] = USHORT,

		[('b' - '@')] = USHORT,
	},
/*
** 4: hh-prefixed
*/
	{
		[('d' - '@')] = CHAR,
		[('i' - '@')] = CHAR,
		[('o' - '@')] = UCHAR,
		[('u' - '@')] = UCHAR,
		[('x' - '@')] = UCHAR,
		[('X' - '@')] = UCHAR,

		[('b' - '@')] = UCHAR,
	},
/*
** 5: L-prefixed
*/
	{
		[('f' - '@')] = LDBL,
	},
/*
** 6: z- or t-prefixed (assumed to be same size)
*/
	{
		[('d' - '@')] = PDIFF,
		[('i' - '@')] = PDIFF,
		[('o' - '@')] = SIZET,
		[('u' - '@')] = SIZET,
		[('x' - '@')] = SIZET,
		[('X' - '@')] = SIZET,

		[('b' - '@')] = SIZET,
	},
/*
** 7: j-prefixed
*/
	{
		[('d' - '@')] = IMAX,
		[('i' - '@')] = IMAX,
		[('o' - '@')] = UMAX,
		[('u' - '@')] = UMAX,
		[('x' - '@')] = UMAX,
		[('X' - '@')] = UMAX,

		[('b' - '@')] = UMAX,
	}
};

static void			pfpopunsigned(t_arg *arg, int type, va_list ap)
{
	if (type == UIPTR)
		arg->l = (unsigned long)va_arg(ap, void*);
	else if (type == UCHAR)
		arg->l = (unsigned char)va_arg(ap, unsigned int);
	else if (type == USHORT)
		arg->l = (unsigned short)va_arg(ap, unsigned int);
	else if (type == UINT)
		arg->l = va_arg(ap, unsigned int);
	else if (type == ULONG)
		arg->l = va_arg(ap, unsigned long);
	else if (type == ULLONG)
		arg->l = va_arg(ap, unsigned long long);
	else if (type == SIZET)
		arg->l = va_arg(ap, size_t);
	else if (type == UMAX)
		arg->l = va_arg(ap, uintmax_t);
	else if (type == PDIFF)
		arg->l = va_arg(ap, ptrdiff_t);
	else
		arg->p = NULL;
}

static void			pfpop(t_arg *arg, int type, va_list ap)
{
	if (type == NOARG)
		arg->p = NULL;
	else if (type == PTR)
		arg->p = va_arg(ap, void*);
	else if (type == CHAR)
		arg->l = (char)va_arg(ap, int);
	else if (type == SHORT)
		arg->l = (short)va_arg(ap, int);
	else if (type == INT)
		arg->l = va_arg(ap, int);
	else if (type == LONG)
		arg->l = va_arg(ap, long);
	else if (type == LLONG)
		arg->l = va_arg(ap, long long);
	else if (type == DBL)
		arg->f = va_arg(ap, double);
	else if (type == LDBL)
		arg->f = va_arg(ap, long double);
	else if (type == IMAX)
		arg->l = va_arg(ap, intmax_t);
	else
		pfpopunsigned(arg, type, ap);
}

int					pfcall(t_flag *flag, va_list ap)
{
	t_arg arg;

	if (!g_handlers[flag->type - '@'])
		return (-1);
	if (!flag->length)
		pfpop(&arg, g_types[BARE][flag->type - '@'], ap);
	else if (flag->length[0] == 'l' && flag->length[1] == 'l')
		pfpop(&arg, g_types[LLPRE][flag->type - '@'], ap);
	else if (flag->length[0] == 'h' && flag->length[1] == 'h')
		pfpop(&arg, g_types[HHPRE][flag->type - '@'], ap);
	else if (flag->length[0] == 'l')
		pfpop(&arg, g_types[LPRE][flag->type - '@'], ap);
	else if (flag->length[0] == 'h')
		pfpop(&arg, g_types[HPRE][flag->type - '@'], ap);
	else if (flag->length[0] == 'L')
		pfpop(&arg, g_types[BLPRE][flag->type - '@'], ap);
	else if (flag->length[0] == 'z' || flag->length[0] == 't')
		pfpop(&arg, g_types[ZPRE][flag->type - '@'], ap);
	else if (flag->length[0] == 'j')
		pfpop(&arg, g_types[JPRE][flag->type - '@'], ap);
	else
		pfpop(&arg, g_types[BARE][flag->type - '@'], ap);
	g_handlers[flag->type - '@'](&arg, flag);
	return (0);
}

int					pfisvalid(char type)
{
	return (!!g_handlers[type - '@']);
}

void				ft_pfregister(
		char type,
		t_handler handler,
		int length)
{
	if (type - '@' > 'z' - '@' + 1 || !handler)
		return ;
	g_handlers[type - '@'] = handler;
	g_types[BARE][type - '@'] = length;
}
