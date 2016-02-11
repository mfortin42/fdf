/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:55:51 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/11 12:11:34 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_print_point(t_env *e, unsigned int y, unsigned int x)
{
	double	const_y;
	double	const_x;

	const_y = 0.1;
	const_x = 0.1;
	e->x_prim = -const_y * (double)(y) + const_x * (double)(x);
	e->y_prim = -((double)e->v_tab[y][x] / 5) + (const_y / 2) * (double)(y) + (const_x / 2) * (double)(x);
}

void	ft_print_grid(t_env *e)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	e->zoom = 100;
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

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	ft_size_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	ft_second_read(t_env *e, int fd)
{
	char			*line;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if ((e->v_tab = (int **)malloc(sizeof(int *) * e->l_nbr)) == NULL)
		ft_error("error : malloc failed");
	while ((get_next_line(fd, &line)) > 0)
	{
		e->v_tab_tmp = ft_strsplit(line, ' ');
		if ((ft_size_tab(e->v_tab_tmp)) != e->c_nbr)
			ft_error("error : pas le meme nombre de colonnes entre les lignes");
		if ((e->v_tab[i] = (int *)malloc(sizeof(int) * e->c_nbr)) == NULL)
			ft_error("error : malloc failed");
		j = 0;
		while (j < e->c_nbr)
		{
			e->v_tab[i][j] = ft_atoi(e->v_tab_tmp[j]);
			j++;
		}
		i++;
		free(line);
	}
}

void	ft_free_line_tab(char **str)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		tmp = str[i];
		free(tmp);
		i++;
	}
	free(str);
}

void	ft_first_read(t_env *e, int fd)
{
	char			*line;
	unsigned int	i;

	e->l_nbr = 0;
	e->c_nbr = 0;
	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (e->l_nbr == 0)
		{
			e->v_tab_tmp = ft_strsplit(line, ' ');
			while (e->v_tab_tmp[i])
			{
				e->c_nbr++;
				i++;
			}
			ft_free_line_tab(e->v_tab_tmp);
		}
		e->l_nbr++;
		free(line);
	}
}

t_env	*ft_parsing(t_env *e, char *file)
{
	if ((e->fd = open(file, O_RDONLY)) < 0)
		ft_error("error : open failed");
	ft_first_read(e, e->fd);
	if ((close(e->fd)) < 0)
		ft_error("error : close failed");
	if ((e->fd = open(file, O_RDONLY)) < 0)
		ft_error("error : open failed");
	ft_second_read(e, e->fd);
	if ((close(e->fd)) < 0)
		ft_error("error : close failed");
	return (e);
}

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
		ft_print_grid(&e);
		mlx_loop(e.mlx);
	}
	else
		ft_error("error : pas le bon nombre d'arguments");
	ft_putstr("nombre de ligne : ");
	ft_putnbr(e.l_nbr);
	ft_putchar('\n');
	ft_putstr("nombre de colonne : ");
	ft_putnbr(e.c_nbr);
	ft_putchar('\n');
	ft_putstr("CONTENU DU INT** (map) :");
	ft_putchar('\n');
	while (j < e.l_nbr)
	{
		while (i < e.c_nbr)
		{
			ft_putnbr(e.v_tab[j][i]);
			i++;
		}
		i = 0;
		ft_putchar('\n');
		j++;
	}
	return (0);
}
