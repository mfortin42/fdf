/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:55:51 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/13 18:47:47 by mfortin          ###   ########.fr       */
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
		e.pow_z = 50;
		ft_parsing(&e, argv[1]);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Fdf");
		mlx_key_hook(e.win, ft_exit_fdf, &e);
		mlx_clear_window(e.mlx, e.win);
		mlx_loop_hook(e.mlx, ft_print_grid, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error("error : pas le bon nombre d'arguments\n");
	return (0);
}
