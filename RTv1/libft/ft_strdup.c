/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:18:56 by owinckle          #+#    #+#             */
/*   Updated: 2015/12/15 11:47:21 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*cpy_str;

	i = 0;
	len = ft_strlen(s1);
	cpy_str = (char*)malloc(sizeof(char) * (len + 1));
	if (cpy_str == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (s1[i])
	{
		cpy_str[i] = s1[i];
		i++;
	}
	cpy_str[i] = '\0';
	return (cpy_str);
}
