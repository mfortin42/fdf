/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:47:33 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/18 11:58:21 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
