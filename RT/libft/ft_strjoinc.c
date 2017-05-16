/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 09:18:19 by dbirtel           #+#    #+#             */
/*   Updated: 2015/12/20 10:01:24 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinc(char *s, char c)
{
	char	*new;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s) + i;
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	return (new);
}
