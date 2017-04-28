/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 09:39:20 by dbirtel           #+#    #+#             */
/*   Updated: 2015/12/17 11:04:54 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t len)
{
	int		i;
	int		j;
	int		k;
	size_t	l;

	i = 0;
	if (s1[i] == 0 && s2[i] == 0)
		return ((char *)s1);
	while (s1[i] && len > 0)
	{
		j = 0;
		k = i;
		l = len;
		while (s1[k] == s2[j] && l > 0 && s1[k] != '\0')
		{
			k++;
			j++;
			l--;
		}
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
		len--;
	}
	return (NULL);
}
