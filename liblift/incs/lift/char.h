/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:31:45 by lroux             #+#    #+#             */
/*   Updated: 2019/03/28 18:24:09 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFT_CHAR_H
# define LIFT_CHAR_H

/*
**  _ _ _     _ _  __ _
** | (_) |   | (_)/ _| |
** | |_| |__ | |_| |_| |_
** | | | '_ \| | |  _| __|
** | | | |_) | | | | | |_
** |_|_|_.__/|_|_|_|  \__|
**
** Part `char`:
**   - Char tests.
**   - Char modifiers.
*/

# define CHAR_SPACES	"\t\n\v\f\r "

# define CHAR_LALPHA	"abcdefghijklmnopqrstuvwxyz"
# define CHAR_UALPHA	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define CHAR_ALPHA		LALPHA_CHARS UALPHA_CHARS

# define CHAR_DIGITS	"0123456789"
# define CHAR_XDIGITS	CHAR_DIGITS "abcdefABCDEF"

int	ft_inset(int c, const char *charset);

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_isspace(int c);
int	ft_isupper(int c);
int	ft_islower(int c);

int	ft_toupper(int c);
int	ft_tolower(int c);

#endif
