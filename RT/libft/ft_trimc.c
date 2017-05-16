/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 09:46:49 by dbirtel           #+#    #+#             */
/*   Updated: 2016/02/03 18:27:03 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trimc(char const *s, char c)
{
	int		i;
	int		len;
	int		start;

	i = 0;
	while (s[i] == c)
		i++;
	start = i;
	while (s[i] != 0)
		i++;
	while (s[i] == c)
		i--;
	len = i - start;
	return (ft_strsub(s, start, len));
}
