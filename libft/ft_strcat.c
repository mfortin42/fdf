/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:47:21 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/18 11:57:53 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int i;
	unsigned int dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
