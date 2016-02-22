/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:37:48 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/22 22:31:51 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIN_Y 1080
# define WIN_X 1920

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define ESC 53
# define MORE 69
# define LESS 78
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define PAGE_UP 116
# define PAGE_DOWN 121
# define RESET 82

typedef struct		s_env
{
	void			*mlx;
	void			*win;

	void			*im;
	char			*imc;
	int				bpp;
	int				imlen;
	int				endi;

	unsigned int	l_nbr;
	unsigned int	c_nbr;
	char			**v_tab_tmp;
	int				**v_tab;

	float			zoom;
	float			ori_x;
	float			ori_y;
	float			const_y;
	float			const_x;
	int				pow_z;

	int				x_prim;
	int				y_prim;
	int				x_next_prim;
	int				y_next_prim;
	int				x_next;
	int				y_next;
	int				actual_z;

	int				error;
	int				tmp_error;
	int				tmpx;
	int				tmpy;
	int				dx;
	int				dy;
	int				sx;
	int				sy;

	int				lr;
	int				ud;
	int				p_ud;
	int				ml;
	int				reset;

}					t_env;

int					ft_key_biding(int keycode, t_env *e);
int					ft_key_release(int keycode, t_env *e);
int					ft_key_core(t_env *e);
void				ft_do_key(t_env *e);

void				ft_ini_val(t_env *e);
t_env				*ft_parsing(t_env *e, char *file);
void				ft_first_read(t_env *e, int fd);
void				ft_second_read(t_env *e, int fd);
void				ft_check_char_print(char *str);
void				ft_print_settings(void);

int					ft_print_grid(t_env *e);
void				ft_print_point(t_env *e, unsigned int y, unsigned int x);
void				ft_print_next1(t_env *e, unsigned int y, unsigned int x);
void				ft_print_next2(t_env *e, unsigned int y, unsigned int x);
void				ft_draw_line(int x2, int y2, t_env *e, int direct);
void				ft_color(int x, int y, t_env *e, int direct);

void				ft_error(char *str);
void				ft_free_line_tab(char **str);
unsigned int		ft_size_tab(char **str);
void				ft_put_pixel(t_env *e, int x, int y, int color);

#endif
