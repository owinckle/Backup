/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:07:44 by dbirtel           #+#    #+#             */
/*   Updated: 2015/12/15 08:26:48 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst2;
	unsigned char	*src2;
	size_t			i;

	i = -1;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (++i < n)
	{
		*(dst2 + i) = *(src2 + i);
		if (*(src2 + i) == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
