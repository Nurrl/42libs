/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgc.both.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:05:55 by lroux             #+#    #+#             */
/*   Updated: 2019/01/08 17:23:18 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGC_BOTH_H
# define LIBGC_BOTH_H

/*
** Secured main definition,
** to ensure the prototype is okay.
*/
int		smain();
int		smain(int ac, char **av);

#endif
