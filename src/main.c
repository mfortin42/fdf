/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:55:51 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/18 17:17:04 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_print_notice(void)
{
	ft_putstr("\n\n      ================================================");
	ft_putstr("\n      |           WELCOLME TO WORLD OF FDF           |\n");
	ft_putstr("      ================================================\n\n");
	ft_putstr("              HERE'S HOW TO INTERACT WITH FDF:\n");
	ft_putstr("      ------------------------------------------------\n");
	ft_putstr("      |       KEY       |           ACTION           |\n");
	ft_putstr("      ------------------------------------------------\n");
	ft_putstr("      |      'esc'      |      exit the programm     |\n");
	ft_putstr("      |    'page up'    |          zoom in           |\n");
	ft_putstr("      |   'page down'   |          zoom out          |\n");
	ft_putstr("      |       '+'       |       increase height      |\n");
	ft_putstr("      |       '-'       |       decrease height      |\n");
	ft_putstr("      |      'UP'       |          move up           |\n");
	ft_putstr("      |     'DOWN'      |         move down          |\n");
	ft_putstr("      |     'LEFT'      |         move left          |\n");
	ft_putstr("      |     'RIGHT'     |         move right         |\n");
	ft_putstr("      ------------------------------------------------\n\n\n");
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc == 2)
	{
		ft_parsing(&e, argv[1]);
		ft_ini_val(&e);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Fdf");
		ft_print_notice();
		ft_print_grid(&e);
		mlx_key_hook(e.win, ft_exit_fdf, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error("error : wrong number of arguments\n");
	return (0);
}
