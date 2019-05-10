/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 06:13:06 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 21:48:49 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFT_MATH_H
# define LIFT_MATH_H

/*
**  _ _ _     _ _  __ _
** | (_) |   | (_)/ _| |
** | |_| |__ | |_| |_| |_
** | | | '_ \| | |  _| __|
** | | | |_) | | | | | |_
** |_|_|_.__/|_|_|_|  \__|
**
** Part `math`:
**   - Mathemcatifal functions.
**   - Convert `int` <> `str` utils.
*/

# define BASE36 "0123456789abcdefghijklmnopqrstuvwxyz"

long long		ft_min(long long a, long long b);

long			ft_sqrt(long nb);
long long		ft_pow(long long x, unsigned long long y);

char			ft_intlen(long long n, int base);
char			ft_uintlen(unsigned long long n, int base);

char			*ft_itostr(long long num, int base);
void			ft_itostrb(char *buf, long long num,
			int base, int precision);
char			*ft_utostr(unsigned long long num, int base);
void			ft_utostrb(char *buf, unsigned long long num,
			int base, int precision);

int				ft_atoi(const char *str);
long long		ft_strtoll(const char *str, char **endptr, int base);

#endif
