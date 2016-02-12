/ ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:20:35 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/12 14:55:36 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
/*
void	ft_draw(t_env *e, unsigned int y, unsigned int x)
{
	if (y < (e->l_nbr - 1) && x < (e->c_nbr - 1))
		ft_print_next(e, y, x);
	else if (x < e->c_nbr - 1)
		ft_print_next2(e, y, x);
	else if (y < e->l_nbr - 1)
		ft_print_next3(e, y, x); 
}
*/
void	ft_print_grid(t_env *e)
{
	unsigned int y;
	unsigned int x;

	y = 0;
	e->zoom = (WIN_Y) / (((e->l_nbr) + (e->c_nbr)) / 10);
	e->ori_y = WIN_Y / 5 * 2;
	e->ori_x = WIN_X / 5 * 2;
	while (y < e->l_nbr)
	{
		x = 0;
		while (x < e->c_nbr)
		{
			ft_print_point(e, y, x);
				mlx_pixel_put(e->mlx, e->win, e->x_prim * e->zoom + e->ori_x,
						e->y_prim * e->zoom + e->ori_y, 0xFFFF);
			//ft_draw(e, y, x);
			x++;
		}
		y++;
	}
}

void	ft_print_point(t_env *e, unsigned int y, unsigned int x)
{
	e->const_y = 0.1;
	e->const_x = 0.1;
	e->x_prim = -e->const_y * (double)(y) + e->const_x * (double)(x);
	e->y_prim = -((double)e->v_tab[y][x] / 10) + (e->const_y / 2) * (double)(y) + (e->const_x / 2) * (double)(x);
}
/*
void	ft_print_next(t_env *e, unsigned int y, unsigned int x)
{
	e->x_next = e->v_tab[y][x + 1];
	e->y_next = e->v_tab[y + 1][x];
	e->x_next_prim1 = -e->const_y * (double)(y + 1) - e->const_x * (double)(x);
	e->y_next_prim1 = -((double)e->x_next / 50) + (e->const_y / 2) * (double)(y + 1) + (e->const_x / 2) * (double)(x);
	e->x_next_prim2 = -e->const_y * (double)(y) - e->const_x * (double)(x + 1);
	e->y_next_prim2 = -((double)e->y_next / 50) + (e->const_y / 2) * (double)y + (e->const_x / 2) * (double)(x + 1);
	ft_draw_line((e->x_next_prim1 * e->zoom + e->ori_x) , (e->y_next_prim1 * e->zoom + e->ori_y), e);
	ft_draw_line((e->x_next_prim2 * e->zoom + e->ori_x) , (e->y_next_prim2 * e->zoom + e->ori_y), e);
}

void	ft_print_next2(t_env *e, unsigned int y, unsigned int x)
{
	e->x_next = e->v_tab[y][x + 1];
	e->x_next_prim1 = -e->const_y * (double)(y + 1) - e->const_x * (double)(x);
	e->y_next_prim1 = -((double)e->x_next / 50) + (e->const_y / 2) * (double)(y + 1) + (e->const_x / 2) * (double)(x);
	ft_draw_line((e->x_next_prim1 * e->zoom + e->ori_x) , (e->y_next_prim1 * e->zoom + e->ori_y), e);
}

void	ft_print_next3(t_env *e, unsigned int y, unsigned int x)
{
	e->y_next = e->v_tab[y + 1][x];
	e->x_next_prim2 = -e->const_y * (double)(y) - e->const_x * (double)(x + 1);
	e->y_next_prim2 = -((double)e->y_next / 50) + (e->const_y / 2) * (double)(y) + (e->const_x / 2) * (double)(x + 1);
	ft_draw_line((e->x_next_prim2 * e->zoom + e->ori_x) , (e->y_next_prim2 * e->zoom + e->ori_y), e);
}

void	ft_draw_line(int x2, int y2, t_env *e)
{
	int	err;
	int	e2;

	e->xn = (e->x_prim * e->zoom + e->ori_x);
	e->yn = (e->y_prim * e->zoom + e->ori_y);
	e->dx = abs(x2 - e->xn);
	e->dy = abs(y2 - e->yn);
	e->sx = e->xn < x2 ? 1 : -1;
	e->sy = e->yn < y2 ? 1 : -1;
	err = (e->dx > e->dy ? e->dx : -(e->dy)) / 2;
	while (e->xn != x2 && e->yn != y2)
	{
		mlx_pixel_put(e->mlx, e->win, e->xn, e->yn, 0x00FFFF);
		e2 = err;
		if (e2 > -(e->dx))
		{
			err -= (e->dy);
			e->xn += e->sx;
		}
		if (e2 < (e->dy))
		{
			err += (e->dx);
			e->yn += e->sy;
		}
	}
}
*/
