/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 09:57:15 by dbirtel           #+#    #+#             */
/*   Updated: 2016/02/01 10:18:48 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len && s[i])
	{
		new[i] = s[i];
		i++;
	}
	while (i < len)
	{
		new[i] = '\0';
		i++;
	}
	if (i == len)
		new[i] = '\0';
	return (new);
}
