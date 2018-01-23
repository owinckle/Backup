/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:39:24 by owinckle          #+#    #+#             */
/*   Updated: 2018/01/23 17:39:24 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dup)
	{
		i = 0;
		while (str[i])
		{
			dup[i] = str[i];
			i++;
		}
		dup[i] = '\0';
		return (dup);
	}
	return (NULL);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len;
	int		i;

	new = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		i = 0;
		if (!(new = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (*s1)
			new[i++] = *s1++;
		while (*s2)
			new[i++] = *s2++;
		new[i] = '\0';
	}
	else if (s1)
		return (ft_strdup(s1));
	else if (s2)
		return (ft_strdup(s2));
	return (new);
}
