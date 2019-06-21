/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 01:12:04 by lroux             #+#    #+#             */
/*   Updated: 2019/06/18 01:42:16 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGP_H
# define ARGP_H

# include "lift/types.h"
# include <stdarg.h>
# include <stddef.h>

/*
**  _ _ _     _ _  __ _
** | (_) |   | (_)/ _| |
** | |_| |__ | |_| |_| |_
** | | | '_ \| | |  _| __|
** | | | |_) | | | | | |_
** |_|_|_.__/|_|_|_|  \__|
**
** Part `Arg Parse`:
**   - Define argument parsing functions and types.
*/

char	*g_argval;

typedef struct	s_argp {
	char	arg;
	char	*longarg;
	t_bool	hasparam;
}				t_argp;

/*
** Special return values:
**  `?`  - Unknown/unexpected argument
**  `:`  - Plain argument
**  `!`  - Requires a parameter
**  `\0` - No more arguments
**
** Call like this:
** char c;
** while ((c = ft_argp(ac, av, (t_argp*){
**   {'c', "count", true}, // `-c 12` or `--count 12` or `--count=12`
**   {'h', "help", false}, // `-h` or `--help`
**   {0, NULL, false}
** })))
**   ...
*/
char	ft_argp(int ac, char **av, t_argp *list);

#endif
