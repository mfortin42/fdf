/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:20:35 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/11 15:25:59 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_print_grid(t_env *e)
{
	unsigned int y;
	unsigned int x;

	y = 0;
	e->zoom = 200;
	e->ori_y = WIN_Y / 5 * 2;
	e->ori_x = WIN_X / 5 * 2;
	while (y < e->l_nbr)
	{
		x = 0;
		while (x < e->c_nbr)
		{
			ft_print_point(e, y, x);
			mlx_pixel_put(e->mlx, e->win, e->x_prim * e->zoom + e->ori_x,
			e->y_prim * e->zoom + e->ori_y, 0xFF9900);
			x++;
		}
		y++;
	}
}

void	ft_print_point(t_env *e, unsigned int y, unsigned int x)
{
	double const_y;
	double const_x;

	const_y = 0.1;
	const_x = 0.1;
	e->x_prim = -const_y * (double)(y) + const_x * (double)(x);
	e->y_prim = -((double)e->v_tab[y][x] / 10) + (const_y / 2) * (double)(y) + (const_x / 2) * (double)(x);
}
