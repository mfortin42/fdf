/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:55:51 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/20 20:33:43 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc == 2)
	{
		ft_parsing(&e, argv[1]);
		ft_ini_val(&e);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Fdf");
		e.im = mlx_new_image(e.mlx, WIN_X, WIN_Y);
		e.imc = mlx_get_data_addr(e.im, &e.bpp, &e.imlen, &e.endi);
		ft_print_settings();
		ft_print_grid(&e);
		mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_biding, &e);
		mlx_hook(e.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &e);
		mlx_loop_hook(e.mlx, ft_key_core, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error("error : wrong number of arguments.\n");
	return (0);
}
