/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <lroux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:51:41 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 15:02:32 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFT_TYPES_H
# define LIFT_TYPES_H

/*
** Implementation of size-dependent types in C.
*/
typedef signed char	t_int8;
typedef unsigned char	t_uint8;

typedef signed short	t_int16;
typedef unsigned short	t_uint16;

typedef signed int	t_int32;
typedef unsigned int	t_uint32;

typedef signed long long int	t_int64;
typedef unsigned long long int	t_uint64;

/*
** Implementation of boolean type in C,
** protected for inclusion of <stdbool.h>
*/
# ifndef __STDBOOL_H

typedef enum {
	false = 0,
	true = 1
}	t_bool;

# else
#  error "You can't use <stdbool.h> with liblift."
# endif

#endif
