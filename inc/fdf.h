/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:37:48 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/11 15:25:30 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>

# define WIN_X 1920
# define WIN_Y 1080

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				fd;
	unsigned int	l_nbr;
	unsigned int	c_nbr;
	char			**v_tab_tmp;
	int				**v_tab;
	int				ori_x;
	int				ori_y;
	double			x_prim;
	double			y_prim;
	int				zoom;
}					t_env;

t_env				*ft_parsing(t_env *e, char *file);
void				ft_first_read(t_env *e, int fd);
void				ft_second_read(t_env *e, int fd);
void				ft_print_grid(t_env *e);
void				ft_print_point(t_env *e, unsigned int y, unsigned int x);
void				ft_error(char *str);
void				ft_free_line_tab(char **str);
int					ft_size_tab(char **str);

#endif
