/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.intern.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:23:09 by lroux             #+#    #+#             */
/*   Updated: 2018/12/05 17:16:28 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_INTERN_H
# define GNL_INTERN_H

# include "gnl.h"

typedef struct			s_gnldata
{
	char				data[BUFF_SIZE + 1];
	int					descriptor;
	struct s_gnldata	*prev;
	struct s_gnldata	*next;
}						t_gnldata;

#endif
