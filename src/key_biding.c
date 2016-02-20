/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 16:03:44 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/20 17:12:55 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_key_biding(int keycode, t_env *e)
{
	if (keycode == LEFT || keycode == RIGHT)
		e->lr = (keycode == LEFT ? 1 : -1);
	if (keycode == UP || keycode == DOWN)
		e->ud = (keycode == UP ? 1 : -1);
	if (keycode == PAGE_UP || keycode == PAGE_DOWN)
		e->p_ud = (keycode == PAGE_UP ? 1 : -1);
	if (keycode == MORE || keycode == LESS)
		e->ml = (keycode == MORE ? 1 : -1);
	if (keycode == RESET)
		e->reset = (keycode == RESET ? 1 : -1);
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == LEFT || keycode == RIGHT)
		e->lr = 0;
	if (keycode == UP || keycode == DOWN)
		e->ud = 0;
	if (keycode == PAGE_UP || keycode == PAGE_DOWN)
		e->p_ud = 0;
	if (keycode == MORE || keycode == LESS)
		e->ml = 0;
	if (keycode == RESET)
		e->reset = 0;
	return (0);
}

void	ft_do_key_action(t_env *e)
{
	if (e->lr)
		(e->lr == 1 ? (e->ori_x -= 10) : (e->ori_x += 10));
	if (e->ud)
		(e->ud == 1 ? (e->ori_y -= 10) : (e->ori_y += 10));
	if (e->p_ud == 1)
		e->zoom += 5;
	if (e->p_ud == -1 && e->zoom > 5)
		e->zoom -= 5;
	if (e->ml == 1 && e->pow_z > 10)
		e->pow_z -= 2;
	if (e->ml == -1)
		e->pow_z += 2;
	if (e->reset == 1)
		ft_ini_val(e);
}

int		ft_key_core(t_env *e)
{
	mlx_destroy_image(e->mlx, e->im);
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
//	mlx_clear_window(e->mlx, e->win);
	ft_do_key_action(e);
	ft_print_grid(e);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	return (1);
}
