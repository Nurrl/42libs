/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpf.intern.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:49:55 by lroux             #+#    #+#             */
/*   Updated: 2019/01/14 15:25:54 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPF_INTERN_H
# define LIBPF_INTERN_H

# include "libpf.h"
# include <libft.h>

# include <stddef.h>

/*
** Types & macros
*/
# define PF_ERR 0
# define PF_KEK 1

# define FLAGALTER  0x1
# define FLAGMINUS  0x2
# define FLAGPLUS   0x4
# define FLAGBLANK  0x8
# define FLAGZERO   0x10

/*
** Printf substitutions(Bonus)
** Format: {<key>}
**
** Special flags where the content is being replaced
** by a specific constant value.
*/
typedef struct	s_psubst {
	char	*key;
	char	*value;
}				t_psubst;

/*
** Internal functions
*/

t_flag			*pfsubstr(char **format, t_flag *flag);
t_flag			*pflexer(char **format, va_list ap, t_flag *flag);
int				pfcall(t_flag *flag, va_list ap);
int				pfisvalid(char type);

int				pfappend(char **ret, int *count, t_flag flag, t_bool freeit);
int				pfprepend(char *toprepend, char **s, t_bool freeit);

char			*pfdtostr(long double nb, int precision, t_bool point);
char			*pfitostr(long long num, int base, t_flag *flag);
char			*pfutostr(unsigned long long num, int base, int precision);

/*
** Lexer functions
*/

void			pflexparam(t_flag *flag, char **format);
void			pflexflags(t_flag *flag, char **format);
void			pflexwidth(t_flag *flag, char **format, va_list ap);
void			pflexprecision(t_flag *flag, char **format, va_list ap);
int				pflexlandt(t_flag *flag, char **format);

/*
** Param to char* converters
*/

void			pfhandlechar(t_arg *arg, t_flag *flag);
void			pfhandlestr(t_arg *arg, t_flag *flag);
void			pfhandleptr(t_arg *arg, t_flag *flag);

void			pfhandleint(t_arg *arg, t_flag *flag);
void			pfhandleuint(t_arg *arg, t_flag *flag);
void			pfhandlefloat(t_arg *arg, t_flag *flag);
void			pfhandleoct(t_arg *arg, t_flag *flag);
void			pfhandlehex(t_arg *arg, t_flag *flag);
void			pfhandlehexup(t_arg *arg, t_flag *flag);

void			pfhandlebin(t_arg *arg, t_flag *flag);
void			pfhandlenonprint(t_arg *arg, t_flag *flag);

#endif
