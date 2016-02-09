/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:37:48 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/09 18:19:13 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libft/includes/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <errno.h>

# define WIN_X 700
# define WIN_Y 700

typedef struct	s_env
{
	void			*mlx;
	void			*win;
	int				fd;
	unsigned int	l_nbr;
	unsigned int	c_nbr;
	char			**v_tab_tmp;
	int				**v_tab;
}				t_env;

#endif
