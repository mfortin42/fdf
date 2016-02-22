/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:04:13 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/22 22:19:43 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_env		*ft_parsing(t_env *e, char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error("error : failed to open.\n");
	ft_first_read(e, fd);
	if (e->c_nbr == 0)
		ft_error("error : first line is empty.\n");
	if ((close(fd)) < 0)
		ft_error("error : failed to close.\n");
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error("error : failed to open.\n");
	ft_second_read(e, fd);
	if ((close(fd)) < 0)
		ft_error("error : failed to close.\n");
	if (e->c_nbr == 0 && e->l_nbr == 0)
		ft_error("error : wrong number of lines and columns.\n");
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
		ft_error("error : didn't read a file.\n");
}

void		ft_second_read(t_env *e, int fd)
{
	char			*line;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if ((e->v_tab = (int **)malloc(sizeof(int *) * e->l_nbr)) == NULL)
		ft_error("error : malloc failed.\n");
	while ((get_next_line(fd, &line)) > 0)
	{
		ft_check_char_print(line);
		e->v_tab_tmp = ft_strsplit(line, ' ');
		if ((ft_size_tab(e->v_tab_tmp)) != e->c_nbr)
			ft_error("error : wrong number of columns.\n");
		if ((e->v_tab[i] = (int *)malloc(sizeof(int) * e->c_nbr)) == NULL)
			ft_error("error : malloc failed.\n");
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

void		ft_check_char_print(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 && (str[i] != '\t' && str[i] != '\n'
		&& str[i] != '\r' && str[i] != '\v' && str[i] != '\f'))
			ft_error("error : character non printable.\n");
		i++;
	}
}
