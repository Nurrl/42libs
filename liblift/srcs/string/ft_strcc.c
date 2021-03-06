/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 19:53:50 by lroux             #+#    #+#             */
/*   Updated: 2019/03/20 19:20:50 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcc(const char *s, char c)
{
	int count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
		if (*s++ == c)
			count++;
	return (count);
}
