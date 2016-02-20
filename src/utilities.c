/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:55:29 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/20 20:35:56 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void				ft_ini_val(t_env *e)
{
	e->zoom = (WIN_Y) / (((e->l_nbr) + (e->c_nbr)) / 10);
	e->ori_x = WIN_X / 5 * 2.5;
	e->ori_y = WIN_Y / 5 * 2;
	e->const_x = 0.1;
	e->const_y = 0.1;
	e->pow_z = 50;
}

void				ft_print_settings(void)
{
	ft_putstr("\n\n      ================================================");
	ft_putstr("\n      |           WELCOLME TO WORLD OF FDF           |\n");
	ft_putstr("      ================================================\n\n");
	ft_putstr("              HERE'S HOW TO INTERACT WITH FDF:\n");
	ft_putstr("      ------------------------------------------------\n");
	ft_putstr("      |       KEY       |           ACTION           |\n");
	ft_putstr("      ------------------------------------------------\n");
	ft_putstr("      |      'esc'      |      exit the programm     |\n");
	ft_putstr("      |    'page up'    |          zoom in           |\n");
	ft_putstr("      |   'page down'   |          zoom out          |\n");
	ft_putstr("      |       '+'       |       increase height      |\n");
	ft_putstr("      |       '-'       |       decrease height      |\n");
	ft_putstr("      |      'UP'       |          move up           |\n");
	ft_putstr("      |     'DOWN'      |         move down          |\n");
	ft_putstr("      |     'LEFT'      |         move left          |\n");
	ft_putstr("      |     'RIGHT'     |         move right         |\n");
	ft_putstr("      |       '0'       |           reset            |\n");
	ft_putstr("      ------------------------------------------------\n\n\n");
}

void				ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void				ft_free_line_tab(char **str)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		tmp = str[i];
		free(tmp);
		i++;
	}
	free(str);
}

unsigned int		ft_size_tab(char **str)
{
	unsigned int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
