/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:55:51 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/16 16:15:39 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_env	e;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		ft_parsing(&e, argv[1]);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Fdf");
		e.pow_z = 50;
		e.ori_x = WIN_X / 5 * 2;
		e.ori_y = WIN_Y / 5 * 2;
		e.zoom = (WIN_Y) / (((e.l_nbr) + (e.c_nbr)) / 10);
		ft_print_grid(&e);
		mlx_key_hook(e.win, ft_exit_fdf, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error("error : pas le bon nombre d'arguments\n");
	return (0);
}
