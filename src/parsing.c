/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:04:13 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/18 17:10:07 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_env		*ft_parsing(t_env *e, char *file)
{
	if ((e->fd = open(file, O_RDONLY)) < 0)
		ft_error("error : open failed\n");
	ft_first_read(e, e->fd);
	if ((close(e->fd)) < 0)
		ft_error("error : close failed\n");
	if ((e->fd = open(file, O_RDONLY)) < 0)
		ft_error("error : open failed\n");
	ft_second_read(e, e->fd);
	if ((close(e->fd)) < 0)
		ft_error("error : close failed\n");
	return (e);
}

void		ft_first_read(t_env *e, int fd)
{
	char			*line;
	unsigned int	i;
	int				ver;

	e->l_nbr = 0;
	e->c_nbr = 0;
	i = 0;
	while ((ver = (get_next_line(fd, &line))) > 0)
	{
		if (e->l_nbr == 0)
		{
			e->v_tab_tmp = ft_strsplit(line, ' ');
			while (e->v_tab_tmp[i])
			{
				e->c_nbr++;
				i++;
			}
			ft_free_line_tab(e->v_tab_tmp);
		}
		e->l_nbr++;
		free(line);
	}
	if (ver == -1)
		ft_error("error : you don't read a file\n");
}

void		ft_second_read(t_env *e, int fd)
{
	char			*line;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if ((e->v_tab = (int **)malloc(sizeof(int *) * e->l_nbr)) == NULL)
		ft_error("error : malloc failed\n");
	while ((get_next_line(fd, &line)) > 0)
	{
		e->v_tab_tmp = ft_strsplit(line, ' ');
		if ((ft_size_tab(e->v_tab_tmp)) != e->c_nbr)
			ft_error("error : wrong number of colums\n");
		if ((e->v_tab[i] = (int *)malloc(sizeof(int) * e->c_nbr)) == NULL)
			ft_error("error : malloc failed\n");
		j = 0;
		while (j < e->c_nbr)
		{
			e->v_tab[i][j] = ft_atoi(e->v_tab_tmp[j]);
			j++;
		}
		i++;
		free(line);
		ft_free_line_tab(e->v_tab_tmp);
	}
}
