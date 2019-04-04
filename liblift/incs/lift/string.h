/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:13:38 by lroux             #+#    #+#             */
/*   Updated: 2019/03/20 19:45:54 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFT_STRING_H
# define LIFT_STRING_H

/*
** Include for `size_t`.
*/
# include <stdlib.h>

/*
**  _ _ _     _ _  __ _
** | (_) |   | (_)/ _| |
** | |_| |__ | |_| |_| |_
** | | | '_ \| | |  _| __|
** | | | |_) | | | | | |_
** |_|_|_.__/|_|_|_|  \__|
**
** Part `string`:
**   - String copy/information functions.
**   - String compare functions.
**   - String utils.
*/

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *s1, const char *s2, size_t size);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strebrk(const char *s, const char *charset);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
char			*ft_strrep(char *s, char search, char replace);
char			*ft_strnrep(char *s, size_t size, char search, char replace);
size_t			ft_strspn(const char *s, const char *charset);
size_t			ft_strnspn(const char *s, size_t count, const char *charset);
size_t			ft_strcspn(const char *s, const char *charset);
size_t			ft_strncspn(const char *s, size_t count, const char *charset);
char			*ft_strtok(char *str, const char *sep);

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strreset(char **as);
void			ft_strclr(char *s);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strnjoin(const char *s1, const char *s2, size_t n);
char			*ft_strjoinfree(char *s1, const char *s2);
char			*ft_strnjoinfree(char *s1, const char *s2, size_t n);
char			*ft_strtrim(const char *s, int (*check)(int));
char			**ft_strsplit(const char *s, char c);

int				ft_strcc(const char *s, char c);
int				ft_strncc(const char *s, size_t size, char c);
int				ft_strcw(const char *s);

char			*ft_strupr(char *s);
char			*ft_strlwr(char *s);

int				ft_stris(char *s, int (*is)(int c));
int				ft_strisn(char *s, size_t n, int (*is)(int c));

#endif
