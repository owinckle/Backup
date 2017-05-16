/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:06:01 by dbirtel           #+#    #+#             */
/*   Updated: 2016/11/05 12:48:41 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	char	d;
	int		i;

	d = c;
	i = -1;
	if (!s)
		return (NULL);
	if (c == 0)
	{
		while (s[++i])
			;
		return ((char *)(s + i));
	}
	while (s[++i])
		if (s[i] == d)
			return ((char *)(s + i));
	return (NULL);
}
