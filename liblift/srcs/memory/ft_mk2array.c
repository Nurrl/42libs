/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mk2array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <git@heofon.co>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:33:05 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 16:54:40 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lift/memory.h"

void	**ft_mk2array(int x, int y, size_t size)
{
	int		i;
	void	**array;

	if (!(array = ft_calloc(y, sizeof(void*))))
		return (NULL);
	i = -1;
	while (++i < x)
		if (!(array[i] = ft_calloc(x, size)))
			return (NULL);
	return (array);
}
