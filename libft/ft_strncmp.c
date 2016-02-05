/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:48:39 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/18 12:00:10 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
