/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:56:38 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 15:23:51 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFT_IO_H
# define LIFT_IO_H

/*
**  _ _ _     _ _  __ _
** | (_) |   | (_)/ _| |
** | |_| |__ | |_| |_| |_
** | | | '_ \| | |  _| __|
** | | | |_) | | | | | |_
** |_|_|_.__/|_|_|_|  \__|
**
** Part `I/O`:
**   - Define common file descriptors, with a descriptive name.
**   - Input and output functions.
*/

# ifndef BUFF_SIZE
#  define BUFF_SIZE 4096
# endif

# define GNL_READ 1
# define GNL_EOF 0
# define GNL_ERR -1

enum {
	stdin = 0,
	stdout = 1,
	stderr = 2
};

int	gnl(const int fd, char **line);

#endif
