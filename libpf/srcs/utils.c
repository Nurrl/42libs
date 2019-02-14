/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:49:07 by lroux             #+#    #+#             */
/*   Updated: 2019/02/14 04:32:10 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

int		pfappend(char **ret, int *count, t_flag flag, t_bool freeit)
{
	if (!flag.finished)
		return (0);
	if (!(*ret = ft_realloc(*ret, *count + flag.len + 1)))
		return (0);
	ft_memcpy(*ret + *count, flag.finished, flag.len);
	*count += flag.len;
	if (flag.finished && freeit)
		free(flag.finished);
	if (flag.length && freeit)
		free(flag.length);
	return (1);
}

int		pfprepend(char *toprepend, char **s, t_bool freeit)
{
	int len1;
	int len2;

	if (!toprepend || !s)
		return (-1);
	len1 = ft_strlen(*s);
	len2 = ft_strlen(toprepend);
	if (!(*s = ft_realloc(*s, len1 + len2 + 1)))
		return (-1);
	ft_memmove(*s + len2, *s, len1 + 1);
	ft_memcpy(*s, toprepend, len2);
	if (toprepend && freeit)
		free(toprepend);
	return (0);
}

char	*pfdtostr(long double nb, int precision, t_bool point)
{
	char *num;
	char *tmp;

	if (!(num = ft_calloc(precision + 2 + 20 + 1, sizeof(char*))))
		return (NULL);
	if (!(tmp = ft_itostr(nb, 10)))
		return (NULL);
	nb -= (long long)nb;
	if (tmp[0] == '-')
		nb = -nb;
	ft_strcpy(num, tmp);
	free(tmp);
	if (precision > 0 || point)
		ft_strcat(num, ".");
	nb *= ft_pow(10, precision);
	if (!(tmp = ft_itostr(nb, 10)))
		return (NULL);
	ft_strcat(num, tmp);
	free(tmp);
	return (num);
}

char	*pfitostr(long long num, int base, t_flag *flag)
{
	char	*fresh;
	int		index;
	t_bool	invert;

	invert = (num < 0) ? true : false;
	index = ft_intlen(num, base) + ((invert) ? -1 : 0);
	index += (flag->precision <= index) ? 0 : (flag->precision - index);
	if (!(fresh = ft_strnew(index + 1)))
		return (NULL);
	while (index)
	{
		fresh[--index] = "0123456789abcdef"[(invert)
			? -(num % base) : (num % base)];
		num = num / base;
	}
	if (invert)
		flag->leading = "-";
	else if (flag->flags & FLAGPLUS)
		flag->leading = "+";
	else if (flag->flags & FLAGBLANK)
		flag->leading = " ";
	if (flag->precision == 0 && fresh[0] == '0')
		fresh[0] = 0;
	return (fresh);
}

char	*pfutostr(unsigned long long num, int base, int precision)
{
	char	*fresh;
	int		index;

	index = ft_uintlen(num, base);
	index += (precision <= index) ? 0 : (precision - index);
	if (!(fresh = ft_strnew(index + 1)))
		return (NULL);
	while (index)
	{
		fresh[--index] = "0123456789abcdef"[(num % base)];
		num = num / base;
	}
	return (fresh);
}
