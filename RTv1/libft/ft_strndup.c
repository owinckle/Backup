/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:38:29 by owinckle          #+#    #+#             */
/*   Updated: 2016/02/04 17:53:21 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <errno.h>

void	*ft_strndup(const char *s1, size_t n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char*)malloc((n + 1) * sizeof(*s1));
	if (ptr)
	{
		while (n--)
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
	}
	else
	{
		errno = ENOMEM;
		return (0);
	}
	return (ptr);
}
