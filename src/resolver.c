/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:20:35 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/17 17:31:55 by mfortin          ###   ########.fr       */
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
	e->const_y = 0.1;
	e->const_x = 0.1;
	e->x_prim = (-e->const_y * y + e->const_x * x) * e->zoom + e->ori_x;
	e->y_prim = (-((float)e->v_tab[y][x] / e->pow_z) + (e->const_y / 2) * y + (e->const_x / 2) * x) * e->zoom + e->ori_y;
	if (y < (e->l_nbr - 1) && x < (e->c_nbr - 1))
	{
		ft_print_next1(e, y, x);
		ft_print_next2(e, y, x);
	}
	else if (x < e->c_nbr - 1)
		ft_print_next1(e, y, x);
	else if (y < e->l_nbr - 1)
		ft_print_next2(e, y, x);
}

void	ft_print_next1(t_env *e, unsigned int y, unsigned int x)
{
	e->x_next = e->v_tab[y][x + 1];
	e->x_next_prim1 = (-e->const_y * y + e->const_x * (x + 1)) * e->zoom + e->ori_x;
	e->y_next_prim1 = (-((float)e->x_next / e->pow_z) + (e->const_y / 2) * y + (e->const_x / 2) * (x + 1)) * e->zoom + e->ori_y;
	ft_draw_line(e->x_next_prim1, e->y_next_prim1, e);
}

void	ft_print_next2(t_env *e, unsigned int y, unsigned int x)
{
	e->y_next = e->v_tab[y + 1][x];
	e->x_next_prim2 = (-e->const_y * (y + 1) + e->const_x * x) * e->zoom + e->ori_x;
	e->y_next_prim2 = (-((float)e->y_next / e->pow_z) + (e->const_y / 2) * (y + 1) + (e->const_x / 2) * x) * e->zoom + e->ori_y;
	ft_draw_line(e->x_next_prim2, e->y_next_prim2, e);
}

void	ft_draw_line(int x2, int y2, t_env *e)
{
	int	err;
	int	e2;
	int	tmpx;
	int	tmpy;

	tmpx = e->x_prim;
	tmpy = e->y_prim;
	e->dx = abs(x2 - (int)e->x_prim);
	e->dy = abs(y2 - (int)e->y_prim);
	e->sx = e->x_prim < x2 ? 1 : -1;
	e->sy = e->y_prim < y2 ? 1 : -1;
	err = (e->dx > e->dy ? e->dx : -(e->dy)) / 2;
	while (!(e->y_prim == y2 && e->x_prim == x2))
	{
		mlx_pixel_put(e->mlx, e->win, e->x_prim, e->y_prim, 0xFFFF);
		e2 = err;
		if (e2 > -(e->dx))
		{
			err -= (e->dy);
			e->x_prim += e->sx;
		}
		if (e2 < (e->dy))
		{
			err += (e->dx);
			e->y_prim += e->sy;
		}
	}
	e->x_prim = tmpx;
	e->y_prim = tmpy;
}
