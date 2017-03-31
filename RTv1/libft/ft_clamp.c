/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:38:26 by owinckle          #+#    #+#             */
/*   Updated: 2017/02/28 10:38:57 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_clamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return (value);
}
