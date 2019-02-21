/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:04:30 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 16:55:40 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lift/memory.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!(new = malloc(size)))
		return (NULL);
	ft_memcpy(new, ptr, size);
	ft_memdel(&ptr);
	return (new);
}
