/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:07:13 by lroux             #+#    #+#             */
/*   Updated: 2019/01/15 14:26:57 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			getvalue(char c, int base)
{
	if (ft_isdigit(c))
		c -= '0';
	else if (ft_isalpha(c))
		c = c - ((ft_islower(c)) ? 'a' : 'A') + 10;
	else
		return (-1);
	if (c >= base)
		return (-1);
	return (c);
}

static t_bool		prepareit(char **str, int *base, t_bool *invert)
{
	t_bool hashexmark;

	while (ft_isspace(**str))
		(*str)++;
	*invert = false;
	if ((*str)[0] == '-' && (*invert = true) == true)
		(*str)++;
	else if (*str[0] == '+')
		(*str)++;
	hashexmark = false;
	if ((*str)[0] == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X'))
		hashexmark = true;
	if (*base == 0 && hashexmark)
		*base = 16;
	else if (*base == 0)
		*base = ((*str)[0] == '0') ? 8 : 10;
	if (*base < 2 || *base > 36)
		return (false);
	if (*base == 16 && hashexmark)
		*str += (getvalue(*(*str + 2), *base) == -1) ? 1 : 2;
	if (getvalue(**str, *base) == -1 && !hashexmark)
		return (false);
	return (true);
}

static t_bool		calculate(long long *num, int base,
		char **str, t_bool invert)
{
	long long	cutoff;
	int			cutlim;
	char		c;

	cutoff = (invert) ? -(unsigned long long)LLONG_MIN : LLONG_MAX;
	cutlim = cutoff % (unsigned long long)base;
	cutoff /= (unsigned long long)base;
	*num = 0;
	while ((c = *(*str)++))
	{
		if ((c = getvalue(c, base)) == -1)
			break ;
		if (*num > cutoff || (*num == cutoff && c > cutlim))
			return (false);
		*num = *num * base + c;
	}
	return (true);
}

long long			ft_strtoll(const char *str, char **endptr, int base)
{
	char		*s;
	long long	num;
	t_bool		invert;

	s = (char*)str;
	if (!prepareit(&s, &base, &invert))
	{
		if (endptr)
			*endptr = (char*)str;
		errno = EINVAL;
		return (0);
	}
	if (!calculate(&num, base, &s, invert))
	{
		if (endptr)
			*endptr = (char*)str;
		errno = ERANGE;
		return ((invert) ? LLONG_MIN : LLONG_MAX);
	}
	if (endptr)
		*endptr = (char*)s - 1;
	return ((invert) ? -num : num);
}
