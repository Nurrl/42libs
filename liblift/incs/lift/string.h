/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:13:38 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 16:27:15 by lroux            ###   ########.fr       */
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

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strreset(char **as);
void			ft_strclr(char *s);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strnjoin(const char *s1, const char *s2, size_t n);
char			*ft_strjoinfree(char *s1, const char *s2);
char			*ft_strnjoinfree(char *s1, const char *s2, size_t n);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(const char *s, char c);

int				ft_strcc(const char *s, char c);
int				ft_strcw(const char *s);

char			*ft_strupr(char *s);
char			*ft_strlwr(char *s);

int				ft_strisdigit(char *s);
int				ft_strisndigit(char *s, size_t n);

#endif
