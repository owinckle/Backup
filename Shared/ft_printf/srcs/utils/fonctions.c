/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:45:37 by owinckle          #+#    #+#             */
/*   Updated: 2018/01/23 11:45:37 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
			ft_putstr("-2147483648");
		else
		{
			ft_putchar('-');
			ft_putnbr(-n);
		}
	}
	else if (n >= 0 && n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
