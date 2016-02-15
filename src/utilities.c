/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:55:29 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/15 21:09:44 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_exit_fdf(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		e->pow_z += 30;
	if (keycode == 78)
		e->pow_z -= 30;
	return (0);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
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

unsigned int		ft_size_tab(char **str)
{
	unsigned int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
