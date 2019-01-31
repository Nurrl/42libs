/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:42:32 by lroux             #+#    #+#             */
/*   Updated: 2019/01/17 19:38:52 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# include <string.h>
# include <limits.h>

# include <errno.h>

/*
** Part 0 - Macro & Types
*/

/*
**# if defined(__i386__)
**
**typedef signed char	t_int8;
**typedef unsigned char	t_uint8;
**
**typedef signed int	t_int16;
**typedef unsigned int	t_uint16;
**
**typedef signed long int	t_int32;
**typedef unsigned long int	t_uint32;
**
**typedef signed long long int	t_int64;
**typedef unsigned long long int	t_uint64;
**
**# elif defined(__x86_64__)
*/

typedef signed char	t_int8;
typedef unsigned char	t_uint8;

typedef signed short	t_int16;
typedef unsigned short	t_uint16;

typedef signed int	t_int32;
typedef unsigned int	t_uint32;

typedef signed long long int	t_int64;
typedef unsigned long long int	t_uint64;

typedef long double		t_int80;
typedef unsigned int	t_wint;

/*
**# else
**#  error Unsupported architecture
**# endif
*/

/*
** Don't redefine bool if already defined
*/
# ifndef __STDBOOL_H

typedef enum {
	false = 0,
	true = 1
}	t_bool;

# endif

/*
** Define common file descriptors
*/
typedef enum {
	stdin = 0,
	stdout = 1,
	stderr = 2
}	t_stdfd;

/*
** Part I - Memory operations
** Custom: ft_calloc, ft_realloc.
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			ft_memdel(void **ap);
void			*ft_calloc(size_t count, size_t size);
void			*ft_realloc(void *ptr, size_t size);
void			**ft_mk2array(int x, int y, size_t size);

/*
** Part II - String/Char operations
** Custom: ft_strndup, ft_strnjoin, ft_strreset, ft_strjoinfree,
**  ft_strnjoinfree, ft_strupr, ft_strlwr, ft_strebrk.
*/

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *s1, const char *s2, size_t size);
char			*ft_strebrk(const char *s, const char *charset);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_toupper(int c);
int				ft_tolower(int c);

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strreset(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strnjoin(const char *s1, const char *s2, size_t n);
char			*ft_strjoinfree(char *s1, const char *s2);
char			*ft_strnjoinfree(char *s1, const char *s2, size_t n);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);

int				ft_cc(const char *s, char c);
int				ft_cw(const char *s);

char			*ft_strupr(char *s);
char			*ft_strlwr(char *s);

/*
** Part III - Tests, maths and conversions
** Custom: ft_isupper, ft_islower, ft_isspace, ft_itostr, ft_utostr.c, ft_sqrt,
** ft_strisdigit, ft_strisndigit, ft_strtoll.
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

int				ft_strisdigit(char *s);
int				ft_strisndigit(char *s, size_t n);

long			ft_sqrt(long nb);
long long		ft_pow(long long x, unsigned long long y);

char			ft_intlen(long long n, int base);
char			ft_uintlen(unsigned long long n, int base);

char			*ft_itostr(long long num, int base);
char			*ft_utostr(unsigned long long num, int base);
int				ft_atoi(const char *str);
long long		ft_strtoll(const char *str, char **endptr, int base);

int				ft_isupper(int c);
int				ft_islower(int c);

#endif
