/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subst.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:34:40 by lroux             #+#    #+#             */
/*   Updated: 2018/12/09 15:07:48 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.intern.h"

static const t_psubst g_subs[128] = {
	{"black", "\x1b[30m"},
	{"white", "\x1b[37m"},

	{"red", "\x1b[31m"},
	{"green", "\x1b[32m"},
	{"yellow", "\x1b[33m"},
	{"blue", "\x1b[34m"},
	{"magenta", "\x1b[35m"},
	{"cyan", "\x1b[36m"},
	{"lightred", "\x1b[91m"},
	{"lightgreen", "\x1b[92m"},
	{"lightyellow", "\x1b[93m"},
	{"lightblue", "\x1b[94m"},
	{"lightmagenta", "\x1b[95m"},
	{"lightcyan", "\x1b[96m"},

	{"bold", "\x1b[1m"},
	{"under", "\x1b[4m"},
	{"eoc", "\x1b[0m"},

	{"42", "██╗  ██╗██████╗\n"
		"██║  ██║╚════██╗\n"
		"███████║ █████╔╝\n"
		"╚════██║██╔═══╝\n"
		"     ██║███████╗\n"
		"     ╚═╝╚══════╝"},
	{"shrug", "¯\\_(ツ)_/¯"},
	{NULL, NULL}
};

t_flag	*pfsubstr(char **format, t_flag *flag)
{
	char	*start;
	char	*key;
	int		i;

	start = *format;
	while (**format && **format != '}')
		(*format)++;
	if (!**format || !(key = ft_strndup(start + 1, *format - start - 1)))
		return (NULL);
	i = -1;
	while (g_subs[++i].key)
		if (ft_strequ(g_subs[i].key, key))
			break ;
	free(key);
	if (!g_subs[i].key && ++(*format))
	{
		flag->finished = "{";
		flag->len = 1;
		*format = start + 1;
		return (flag);
	}
	flag->len = ft_strlen(g_subs[i].value);
	flag->finished = g_subs[i].value;
	(*format)++;
	return (flag);
}
