/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:20:35 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/18 16:54:34 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_print_grid(t_env *e)
{
	unsigned int y;
	unsigned int x;

	y = 0;
	while (y < e->l_nbr)
	{
		x = 0;
		while (x < e->c_nbr)
		{
			ft_print_point(e, y, x);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_print_point(t_env *e, unsigned int y, unsigned int x)
{
	e->x_prim = (-e->const_y * y + e->const_x * x) * e->zoom + e->ori_x;
	e->y_prim = (-((float)e->v_tab[y][x] / e->pow_z) + (e->const_y / 2) * y +
				(e->const_x / 2) * x) * e->zoom + e->ori_y;
	if (x < e->c_nbr - 1)
	{
		e->x_next = e->v_tab[y][x + 1];
		e->x_next_prim = (-e->const_y * y + e->const_x * (x + 1)) * e->zoom +
						e->ori_x;
		e->y_next_prim = (-((float)e->x_next / e->pow_z) + (e->const_y / 2) * y
						+ (e->const_x / 2) * (x + 1)) * e->zoom + e->ori_y;
		ft_draw_line(e->x_next_prim, e->y_next_prim, e);
	}
	if (y < e->l_nbr - 1)
	{
		e->y_next = e->v_tab[y + 1][x];
		e->x_next_prim = (-e->const_y * (y + 1) + e->const_x * x) * e->zoom +
						e->ori_x;
		e->y_next_prim = (-((float)e->y_next / e->pow_z) + (e->const_y / 2) *
						(y + 1) + (e->const_x / 2) * x) * e->zoom + e->ori_y;
		ft_draw_line(e->x_next_prim, e->y_next_prim, e);
	}
}

void	ft_draw_line(int x2, int y2, t_env *e)
{
	e->tmpx = e->x_prim;
	e->tmpy = e->y_prim;
	e->dx = abs(x2 - e->x_prim);
	e->dy = abs(y2 - e->y_prim);
	e->sx = e->x_prim < x2 ? 1 : -1;
	e->sy = e->y_prim < y2 ? 1 : -1;
	e->error = (e->dx > e->dy ? e->dx : -(e->dy)) / 2;
	while (!(e->tmpy == y2 && e->tmpx == x2))
	{
		ft_color (e->tmpx, e->tmpy, e);
		e->tmp_error = e->error;
		if (e->tmp_error > -(e->dx))
		{
			e->error -= (e->dy);
			e->tmpx += e->sx;
		}
		if (e->tmp_error < (e->dy))
		{
			e->error += (e->dx);
			e->tmpy += e->sy;
		}
	}
}

void	ft_color(int x, int y, t_env *e)
{
	if (e->x_next == 0)
		mlx_pixel_put(e->mlx, e->win, x, y, 0xFFFFFF);
	else if (e->x_next < 2)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x57CAFF);
	else if (e->x_next < 4)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x4EB5E5);
	else if (e->x_next < 8)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x45A1CC);
	else if (e->x_next < 16)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x3C8DB2);
	else if (e->x_next < 32)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x427999);
	else if (e->x_next < 64)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x2B657F);
	else if (e->x_next < 128)
		mlx_pixel_put(e->mlx, e->win, x, y, 0x225066);
	else
		mlx_pixel_put(e->mlx, e->win, x, y, 0x1A3C4C);
}
