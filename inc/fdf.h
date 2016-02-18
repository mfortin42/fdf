/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:37:48 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/18 15:02:19 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIN_Y 1080
# define WIN_X 1920

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*win2;
	int				fd;

	unsigned int	l_nbr;
	unsigned int	c_nbr;

	char			**v_tab_tmp;
	int				**v_tab;

	float			zoom;
	float			ori_x;
	float			ori_y;
	float			const_y;
	float			const_x;

	int				x_prim;
	int				y_prim;

	int				x_next;
	int				y_next;

	int				x_next_prim;
	int				y_next_prim;

	int				error;
	int				tmp_error;
	int				tmpx;
	int				tmpy;
	int				dx;
	int				dy;
	int				sx;
	int				sy;

	int				pow_z;
}					t_env;

void				ft_ini_val(t_env *e);
t_env				*ft_parsing(t_env *e, char *file);
void				ft_first_read(t_env *e, int fd);
void				ft_second_read(t_env *e, int fd);

int					ft_print_grid(t_env *e);
void				ft_print_point(t_env *e, unsigned int y, unsigned int x);
void				ft_print_next1(t_env *e, unsigned int y, unsigned int x);
void				ft_print_next2(t_env *e, unsigned int y, unsigned int x);
void				ft_draw_line(int x2, int y2, t_env *e);
void				ft_color(int x, int y, t_env *e);

int					ft_exit_fdf(int keycode, t_env *e);
void				ft_error(char *str);
void				ft_free_line_tab(char **str);
unsigned int		ft_size_tab(char **str);

#endif
