/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:48:14 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/18 11:59:32 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t j;
	size_t i;

	j = 0;
	i = 0;
	while (dest[j] && j < n)
		j++;
	while ((src[i]) && ((j + i + 1) < n))
	{
		dest[j + i] = src[i];
		i++;
	}
	if (j != n)
		dest[j + i] = '\0';
	return (j + ft_strlen(src));
}
