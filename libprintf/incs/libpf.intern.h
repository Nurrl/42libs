/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpf.intern.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:49:55 by lroux             #+#    #+#             */
/*   Updated: 2019/03/29 18:48:47 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPF_INTERN_H
# define LIBPF_INTERN_H

# include "libpf.h"
# define NOWARN
# include <lift.h>

# include <stddef.h>
# include <unistd.h>

/*
** Types & macros
*/
# define FLAGALTER  0x1
# define FLAGMINUS  0x2
# define FLAGPLUS   0x4
# define FLAGBLANK  0x8
# define FLAGZERO   0x10

# define BARE  0
# define LPRE  1
# define LLPRE 2
# define HPRE  3
# define HHPRE 4
# define BLPRE 5
# define ZPRE  6
# define JPRE  7
# define MAX   8

# define MAXPRECISION 2048

# define BUFSIZE 4096

/*
** Printf substitutions(Bonus)
** Format: {<key>}
**
** Special flags where the content is being replaced
** by a specific constant value.
*/
typedef struct	s_subs {
	char	*key;
	char	*value;
}				t_subs;

typedef struct	s_pf {
	int		count;

	void	(*store)(struct s_pf *env, const char *s, size_t len);
	void	(*storemove)(struct s_pf *env, char **s, size_t len);

	int		(*flush)(char *buf, size_t size);

	char	*buf;
	size_t	size;
}				t_pf;

/*
** Internal functions
*/

void			pfstart(t_pf *env, char *format, va_list ap);

void			pfspecial(t_pf *env, char **format, va_list ap);
void			pfflag(t_pf *env, char **format, va_list ap);

t_bool			pfisvalid(char type);
t_ret			pfcall(t_flag flag, t_arg *arg, va_list ap);

/*
** Lexer functions
*/

void			pflexparam(t_flag *flag, char **format);
void			pflexflags(t_flag *flag, char **format);
void			pflexwidth(t_flag *flag, char **format, va_list ap);
void			pflexprecision(t_flag *flag, char **format, va_list ap);
t_bool			pflexlandt(t_flag *flag, char **format);
void			pfflaglen(t_flag *flag, char *dum, char **format);

/*
** Param to char* converters
*/

t_ret			pfhandlechar(t_arg *arg, t_flag flag);
t_ret			pfhandlestr(t_arg *arg, t_flag flag);
t_ret			pfhandleptr(t_arg *arg, t_flag flag);

t_ret			pfhandleint(t_arg *arg, t_flag flag);
t_ret			pfhandleuint(t_arg *arg, t_flag flag);
t_ret			pfhandlefloat(t_arg *arg, t_flag flag);
t_ret			pfhandleoct(t_arg *arg, t_flag flag);
t_ret			pfhandlehex(t_arg *arg, t_flag flag);
t_ret			pfhandlehexup(t_arg *arg, t_flag flag);

t_ret			pfhandlebin(t_arg *arg, t_flag flag);

#endif
