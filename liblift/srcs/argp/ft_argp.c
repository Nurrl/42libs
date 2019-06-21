/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:31:23 by lroux             #+#    #+#             */
/*   Updated: 2019/06/18 15:02:37 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/argp.h"
#include "lift/string.h"

int	g_ai = 1;
int	g_idx = 0;

static char	iterate(char c, int *ai, int *idx)
{
	++(*ai);
	*idx = 0;
	return (c);
}

static t_argp	longopt(char *arg, t_argp *list)
{
	t_argp	match;

	++g_idx;
	match = (t_argp){'?', NULL, false};
	while ((*list).arg)
	{
		if ((*list).longarg && ft_strequ(&arg[g_idx], (*list).longarg))
			match = *list;
		++list;
	}
	iterate('\0', &g_ai, &g_idx);
	return (match);
}

static char	opt(char *arg, t_argp *list, char **av, int ac)
{
	t_argp	match;

	match = (t_argp){'?', NULL, false};
	if (g_idx == 1 && arg[g_idx] == '-')
	{
		match = longopt(arg, list);
		if (match.arg == '?')
			g_argval = av[g_ai - 1];
	}
	else
	{
		while ((*list).arg)
		{
			if ((*list).arg == arg[g_idx])
				match = *list;
			++list;
		}
		if (match.arg == '?')
			g_argval = av[g_ai];
		if (match.hasparam)
			iterate('\0', &g_ai, &g_idx);
	}
	if (match.hasparam && g_ai >= ac)
		return ('!');
	else if (match.hasparam)
	{
		g_argval = av[g_ai];
		iterate('\0', &g_ai, &g_idx);
	}
	return (match.arg);
}

char		ft_argp(int ac, char **av, t_argp *list)
{
	static t_bool	bypassarg;

	g_argval = NULL;
	if (g_ai >= ac)
		return ('\0');
	if (bypassarg || (g_idx == 0 && (av[g_ai][g_idx] != '-'
				|| ft_strequ(av[g_ai], "-") || ft_strequ(av[g_ai], "--"))))
	{
		if (!bypassarg && ft_strequ(av[g_ai], "--"))
		{
			bypassarg = true;
			return (iterate('\0', &g_ai, &g_idx) + ft_argp(ac, av, list));
		}
		g_argval = av[g_ai];
		return (iterate(':', &g_ai, &g_idx));
	}
	++g_idx;
	if (!av[g_ai][g_idx])
		return (iterate('\0', &g_ai, &g_idx) + ft_argp(ac, av, list));
	return (opt(av[g_ai], list, av, ac));
}
