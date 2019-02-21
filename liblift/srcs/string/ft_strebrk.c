/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strebrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:30:52 by lroux             #+#    #+#             */
/*   Updated: 2019/02/19 17:50:43 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strebrk(const char *s, const char *charset)
{
	const char *sc;

	sc = charset;
	while (*s)
	{
		while (*charset)
		{
			if (*charset == *s)
				return ((char*)s);
			charset++;
		}
		charset = sc;
		++s;
	}
	return ((char*)s);
}
