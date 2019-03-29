/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:34:40 by lroux             #+#    #+#             */
/*   Updated: 2019/03/29 18:42:22 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.intern.h"

static const t_subs g_subs[128] = {
	{"black", "\x1b[30m"},
	{"red", "\x1b[31m"},
	{"green", "\x1b[32m"},
	{"yellow", "\x1b[33m"},
	{"blue", "\x1b[34m"},
	{"magenta", "\x1b[35m"},
	{"cyan", "\x1b[36m"},
	{"white", "\x1b[37m"},

	{"lightblack", "\x1b[90m"},
	{"lightred", "\x1b[91m"},
	{"lightgreen", "\x1b[92m"},
	{"lightyellow", "\x1b[93m"},
	{"lightblue", "\x1b[94m"},
	{"lightmagenta", "\x1b[95m"},
	{"lightcyan", "\x1b[96m"},
	{"lightwhite", "\x1b[97m"},

	{"bold", "\x1b[1m"},
	{"under", "\x1b[4m"},
	{"rev", "\x1b[7m"},

	{"eoc", "\x1b[0m"},
	{"blank", "\x1b[2J"},

	{"home", "\x1b[H"},
	{"up", "\x1b[A"},
	{"down", "\x1b[B"},
	{"right", "\x1b[C"},
	{"left", "\x1b[D"},

	{"shrug", "¯\\_(ツ)_/¯"},
	{"42",
		"██╗  ██╗██████╗ \n"
		"██║  ██║╚════██╗\n"
		"███████║ █████╔╝\n"
		"╚════██║██╔═══╝ \n"
		"     ██║███████╗\n"
		"     ╚═╝╚══════╝"},
	{"doge",
		"         ▄              ▄    \n"
		"        ▌▒█           ▄▀▒▌   \n"
		"        ▌▒▒█        ▄▀▒▒▒▐   \n"
		"       ▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐   \n"
		"     ▄▄▀▒░▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐   \n"
		"   ▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌   \n"
		"  ▐▒▒▒▄▄▒▒▒▒░░░▒▒▒▒▒▒▒▀▄▒▒▌  \n"
		"  ▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐  \n"
		" ▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌ \n"
		" ▌░▒▄██▄▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌ \n"
		"▐▒▀▐▄█▄█▌▄░▀▒▒░░░░░░░░░░▒▒▒▐ \n"
		"▐▒▒▐▀▐▀▒░▄▄▒▄▒▒▒▒▒▒░▒░▒░▒▒▒▒▌\n"
		"▐▒▒▒▀▀▄▄▒▒▒▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▐ \n"
		" ▌▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒░▒░▒░▒░▒▒▒▌ \n"
		" ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▄▒▒▐  \n"
		"  ▀▄▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▄▒▒▒▒▌  \n"
		"    ▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀   \n"
		"      ▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀     \n"
		"         ▒▒▒▒▒▒▒▒▒▒▀▀        \n"
	},
	{NULL, NULL}
};

static t_bool	colorrgb(t_pf *env, char *key)
{
	(void)key;
	(void)env;
	return (false);
}

static t_bool	color256(t_pf *env, char *key)
{
	key += 6;
	if (!*key || !ft_stris(key, &ft_isdigit))
		return (false);
	env->store(env, "\x1b[38;5;", 7);
	env->store(env, key, ft_strlen(key));
	env->store(env, "m", 1);
	return (true);
}

static t_bool	subs(t_pf *env, char *key)
{
	int i;

	i = -1;
	while (g_subs[++i].key)
		if (ft_strequ(g_subs[i].key, key))
			break ;
	if (!g_subs[i].key)
		return (false);
	env->store(env, g_subs[i].value,
			ft_strlen(g_subs[i].value));
	return (true);
}

static t_bool	dosubstitute(t_pf *env, char *key)
{
	if (ft_strnequ(key, "color;", 6))
	{
		if (ft_strcc(key, ';') == 3)
			return (colorrgb(env, key));
		else
			return (color256(env, key));
	}
	else
		return (subs(env, key));
}

void			pfspecial(t_pf *env, char **format, va_list ap)
{
	char	*start;
	char	*key;

	(void)ap;
	start = *format;
	key = NULL;
	while (**format && **format != '}')
		(*format)++;
	if (!**format || !(key = ft_strndup(start + 1, *format - start - 1))
			|| !dosubstitute(env, key))
	{
		*format = start;
		env->store(env, *format, 1);
	}
	(*format)++;
	free(key);
}
