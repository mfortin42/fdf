/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:55:29 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/18 19:03:28 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
/*
void	do_key(t_env *e)
{
	if (e->lr)
		(e->lr == 1 ? (e->ori_x -= 10) : (e->ori_x += 10));
}

int	ft_key_biding(int keycode, t_env *e)
{
	if (keycode == LEFT || keycode == RIGHT)
		e->lr = (keycode == RIGHT ? -1 : 1);
	return (0);
}

int	ft_key_release(int keycode, t_env *e)
{
	if (keycode == LEFT || keycode == RIGHT)
		e->lr = 0;
	return (0);
}

int	fdf_core(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	do_key(e);
	ft_print_grid(e);
	return (1);
}
*/

int					ft_key_biding(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == LESS)
		e->pow_z += 10;
	if (keycode == MORE)
		if (e->pow_z > 10)
			e->pow_z -= 10;
	if (keycode == LEFT)
		e->ori_x -= 25;
	if (keycode == RIGHT)
		e->ori_x += 25;
	if (keycode == UP)
		e->ori_y -= 25;
	if (keycode == DOWN)
		e->ori_y += 25;
	if (keycode == PAGE_UP)
		e->zoom += 25;
	if (keycode == PAGE_DOWN)
		if (e->zoom > 25)
			e->zoom -= 25;
	mlx_clear_window(e->mlx, e->win);
	ft_print_grid(e);
	return (0);
}

void				ft_ini_val(t_env *e)
{
	e->pow_z = 50;
	e->const_x = 0.1;
	e->const_y = 0.1;
	e->ori_x = WIN_X / 5 * 2.5;
	e->ori_y = WIN_Y / 5 * 2;
	e->zoom = (WIN_Y) / (((e->l_nbr) + (e->c_nbr)) / 10);
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
