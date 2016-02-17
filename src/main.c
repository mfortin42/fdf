/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:55:51 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/17 21:43:17 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc == 2)
	{
		ft_parsing(&e, argv[1]);
		ft_ini_val(&e);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Fdf");
		ft_print_grid(&e);
		mlx_key_hook(e.win, ft_exit_fdf, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error("error : pas le bon nombre d'arguments\n");
	return (0);
}
