/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:22:50 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 16:23:44 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/char.h"

int	ft_tolower(int c)
{
	return (unsigned int)(ft_isupper(c) ? c + 0x20 : c);
}