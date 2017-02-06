/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:42:25 by owinckle          #+#    #+#             */
/*   Updated: 2016/01/05 15:20:01 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s2);
	if (!n)
		return (NULL);
	if (!*s2)
		return ((char*)s1);
	i = 0;
	while (s1[i] && i <= (n - len))
	{
		if (ft_strncmp(&s1[i], s2, len) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
