/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 08:50:28 by dbirtel           #+#    #+#             */
/*   Updated: 2016/02/04 22:13:57 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nbr)
{
	int		i;
	int		len;
	char	*num;

	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(nbr);
	i = len - 1;
	if (!(num = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		num[0] = '-';
	}
	while (nbr > 0)
	{
		num[i--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	num[len] = '\0';
	return (num);
}
