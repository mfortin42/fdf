/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:08:05 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/05 14:00:17 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static t_list	*ft_find_fd(t_list **begin, int fd)
{
	t_list *tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

static char		*ft_free_strnjoin(char *str, char *buff, int ret)
{
	char *tmp;

	tmp = str;
	str = ft_strnjoin(str, buff, ret);
	free(tmp);
	return (str);
}

int				get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				vr;
	static t_list	*list = NULL;
	t_list			*begin;
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buff, 0))
		return (-1);
	begin = list;
	list = ft_find_fd(&begin, fd);
	while (!ft_strchr(list->content, '\n') && (vr = read(fd, buff, BUFF_SIZE)))
		list->content = ft_free_strnjoin(list->content, buff, vr);
	vr = 0;
	while (((char *)list->content)[vr] && ((char *)list->content)[vr] != '\n')
		++vr;
	*line = ft_strndup(list->content, vr);
	if (((char *)list->content)[vr] == '\n')
		++vr;
	tmp = list->content;
	list->content = ft_strdup(list->content + vr);
	free(tmp);
	list = begin;
	return (vr ? 1 : 0);
}
