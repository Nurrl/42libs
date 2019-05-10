/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:49:55 by lroux             #+#    #+#             */
/*   Updated: 2019/04/02 21:46:14 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPF_H
# define LIBPF_H

# include <inttypes.h>
# include <stdarg.h>
# include <stdlib.h>

/*
** Bonuses:
** -- U: Unrealizable for now; x: Done; /:Working but not ok.
**  [x] Sizes 'z/t' and 'j'.
**  [x] %b -> Binary, works with flag '#', and sizes 'z/t' and 'j'.
**  [U] %s
**    -> With precision, if the string is cropped, it will add '..' at the end.
**  [x] %m -> Return of `strerror()`, converts an int, for errno. Passive leak.
**  [U] %n
**    -> Sets the int value to the current written bytes throught an int*.
**  [ ] %f -> Working floats.
**  [U] %r -> Produces `cat -e` exact output.
**  [x]'*' flag for width and precision.
**  [x] {<name>} -> Substitututions with colors/text.
**  [/] {color;<256code>} -> For 256 color codes.
**  [/] {color;<r>;<g>;<b>} -> For RGB color codes.
**  [x] ft_printf()/ft_vprintf();     -> stdout
**  [x] ft_dprintf()/ft_vdprintf();   -> to file descriptor
**  [x] ft_sdprintf()/ft_vsdprintf(); -> to socket descriptor
**  [x] ft_snprintf()/ft_vsnprintf(); -> to string with len
**  [x] ft_asprintf()/ft_vasprintf(); -> to malloc'd string
**  [x] ft_pfreg(); -> Register new converters *WOW*.
*/

/*
** I - Exported types
*/

enum {
	UNSET = 0,
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
** - `str` is a string containing the finished converted form of the arg.
** - `size` is containing the size, in bytes of `str`, in case we
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

int			ft_sdprintf(int sockd, int flags, const char *format, ...);
int			ft_vsdprintf(int sockd, int flags, const char *format, va_list ap);

int			ft_snprintf(char *str,
				size_t size, const char *format, ...);
int			ft_vsnprintf(char *str,
				size_t size, const char *format, va_list ap);

int			ft_asprintf(char **ret, const char *format, ...);
int			ft_vasprintf(char **ret, const char *format, va_list ap);

void		ft_pfreg(char type, t_handler handler, int length);

#endif
