/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:45:07 by lroux             #+#    #+#             */
/*   Updated: 2019/03/03 22:30:34 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

void	pfstart(t_pf *env, char *format, va_list ap)
{
	while (*format)
	{
		if (*format == '{')
			pfspecial(env, &format, ap);
		else if (*format == '%')
			pfflag(env, &format, ap);
		else
			env->count +=
				env->storemove(env, &format, ft_strebrk(format, "{%") - format);
	}
}
