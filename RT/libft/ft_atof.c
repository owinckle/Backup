/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:42:28 by dbirtel           #+#    #+#             */
/*   Updated: 2017/03/30 00:45:43 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	atof_sweet(char *str, double nbr, int sign)
{
	int		i;
	int		dot_len;
	double	dot;

	i = 0;
	dot_len = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		dot = (double)(str[i] - 48);
		++dot_len;
		nbr = nbr + (dot / (double)(pow(10, dot_len)));
		i++;
	}
	return (nbr * (double)sign);
}

double	ft_atof(char *str)
{
	double	nbr;
	int		i;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nbr = (double)((nbr * 10) + (str[i] - 48));
		i++;
	}
	if (str[i] == '.')
		i++;
	return (atof_sweet(str + i, nbr, sign));
}
