/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 09:11:50 by dbirtel           #+#    #+#             */
/*   Updated: 2017/02/16 15:35:48 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	char	*new;
	size_t	len;

	len = ft_strlen(str);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strcpy(new, str);
	new[len] = '\0';
	return (new);
}
