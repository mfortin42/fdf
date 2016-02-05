/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:45:11 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/18 11:52:44 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	char *str;

	if (n == -2147483648)
		return ("-2147483648");
	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}
