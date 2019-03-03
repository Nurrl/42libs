/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:49:55 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 19:01:01 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPF_H
# define LIBPF_H

# include <inttypes.h>
# include <stdarg.h>
# include <stdlib.h>

/*
** Bonus list:
**  Sizes 'z/t' and 'j'.
**  %b -> Binary, works with flag '#', and sizes 'z/t' and 'j'.
**  %s -> With precision, if the string is cropped, it will add '..' at the end.
**  '*' flag for width and precision.
**  {<name>} -> Substitututions with colors/text.
**  ft_pfregister(); -> Register new converters *WOW*.
*/

/*
** I - Exported types
*/

enum {
	PTR, UIPTR,
	CHAR, UCHAR,
	SHORT, USHORT,
	INT, UINT,
	LONG, ULONG,
	LLONG, ULLONG,
	DBL, LDBL,
	SIZET, IMAX, UMAX, PDIFF,
	NOARG,
	MAXSTATE
};

typedef union {
	uintmax_t	l;
	long double	f;
	void		*p;
}	t_arg;

/*
** A single printf flag defined by:
**   -> %[parameter$][flags][width][.precision][length]type
** (Source: Wikipedia.org)
**
** - `leading` is a string containing the leading chars of the *number*.
** - `finished` is a string containing the finished converted form of the arg.
** - `len` is an in containing the length of the `finished` var, in case we
**  want to print a `\0`.
*/
typedef struct {
	int		param;
	int		flags;
	int		width;
	int		precision;
	int		length;
	char	type;
}			t_flag;

typedef struct {
	char	leading[3];
	char	*str;
	size_t	size;
}			t_ret;

typedef t_ret	(*t_handler)(t_arg*, t_flag);

/*
** II - Exported fonctions
*/

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);

int			ft_dprintf(int fd, const char *format, ...);
int			ft_vdprintf(int fd, const char *format, va_list ap);

int			ft_asprintf(char **ret, const char *format, ...);
int			ft_vasprintf(char **ret, const char *format, va_list ap);

int			ft_snprintf(char *str,
				size_t size, const char *format, ...);
int			ft_vsnprintf(char *str,
				size_t size, const char *format, va_list ap);

void		ft_pfregister(char flag, t_handler handler, int type);

#endif
