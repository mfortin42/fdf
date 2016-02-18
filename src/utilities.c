/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:55:29 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/18 14:30:09 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_exit_fdf(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 78)
		e->pow_z += 10;
	else if (keycode == 69)
	{
		if (e->pow_z > 10)
			e->pow_z -= 10;
	}
	else if (keycode == 123)
		e->ori_x -= 25;
	else if (keycode == 124)
		e->ori_x += 25;
	else if (keycode == 126)
		e->ori_y -= 25;
	else if (keycode == 125)
		e->ori_y += 25;
	else if (keycode == 116)
		e->zoom += 25;
	else if (keycode == 121)
		if (e->zoom > 25)
			e->zoom -= 25;
	mlx_clear_window(e->mlx, e->win);
	ft_print_grid(e);
	return (0);
}

void	ft_ini_val(t_env *e)
{
	e->pow_z = 50;
	e->const_x = 0.1;
	e->const_y = 0.1;
	e->ori_x = WIN_X / 5 * 2.5;
	e->ori_y = WIN_Y / 5 * 2;
	e->zoom = (WIN_Y) / (((e->l_nbr) + (e->c_nbr)) / 10);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_free_line_tab(char **str)
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
