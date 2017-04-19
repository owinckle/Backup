/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:34:50 by dbirtel           #+#    #+#             */
/*   Updated: 2016/02/04 23:16:08 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t len)
{
	void	*memory;

	if (!(memory = malloc(sizeof(size_t) * len)) || !len)
		return (NULL);
	ft_bzero(memory, len);
	return (memory);
}
