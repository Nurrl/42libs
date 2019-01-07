/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lroux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:23:00 by lroux             #+#    #+#             */
/*   Updated: 2018/12/30 19:26:27 by lroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.intern.h"
#include "libft.h"

static int	clear(t_gnldata **head, t_gnldata *toclear, char **line)
{
	if (!*head || !toclear)
		return (GNL_ERR);
	if (*head == toclear)
		*head = toclear->next;
	else
	{
		if (toclear->next)
			toclear->next->prev = toclear->prev;
		if (toclear->prev)
			toclear->prev->next = toclear->next;
	}
	free(toclear);
	toclear = NULL;
	free(*line);
	*line = NULL;
	return (GNL_EOF);
}

static int	read_line(int fd, char **line, t_gnldata **head, t_gnldata **cur)
{
	char	*endl;
	int		ret;

	if (!ft_strlen((*cur)->data))
	{
		ret = read((*cur)->descriptor, (*cur)->data, BUFF_SIZE);
		if (ret == -1)
			return (GNL_ERR);
		else if (((*cur)->data[ret] = 0) == 0 && ret == 0 && ft_strlen(*line))
			return (GNL_READ);
	}
	if (!ft_strlen((*cur)->data))
		return (clear(head, *cur, line));
	if (!(endl = ft_strchr((*cur)->data, '\n')))
	{
		if (!(*line = ft_strjoinfree(*line, (*cur)->data)))
			return (GNL_ERR);
		ft_bzero((*cur)->data, BUFF_SIZE + 1);
		return (read_line(fd, line, head, cur));
	}
	if (!(*line = ft_strnjoinfree(*line,
			(*cur)->data, endl - (*cur)->data)))
		return (GNL_ERR);
	ft_memmove((*cur)->data, endl + 1, ft_strlen(endl + 1) + 1);
	return (GNL_READ);
}

int			gnl(const int fd, char **line)
{
	static t_gnldata	*head;
	t_gnldata			*cur;

	if (!line || !(*line = ft_strnew(0)))
		return (GNL_ERR);
	cur = head;
	while (cur)
	{
		if (cur->descriptor == fd)
			return (read_line(fd, line, &head, &cur));
		cur = cur->next;
	}
	if (!(cur = malloc(sizeof(t_gnldata))))
		return (GNL_ERR);
	cur->descriptor = fd;
	ft_bzero(cur->data, BUFF_SIZE + 1);
	cur->next = head;
	if (head)
		head->prev = cur;
	head = cur;
	ft_strdel(line);
	return (gnl(fd, line));
}
