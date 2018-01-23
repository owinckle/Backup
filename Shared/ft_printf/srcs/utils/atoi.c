/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:20:41 by owinckle          #+#    #+#             */
/*   Updated: 2018/01/23 15:20:43 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libftprintf.h"

static int		ft_power(int x, int n)
{
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	while (++i <= n)
		ret *= x;
	return (ret);
}

static char		*ft_rm_whitespace(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] == '\n' || str[i] == '\v' || str[i] == ' ' ||
			str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
			i++;
		return (str + i);
	}
	return (NULL);
}


static char		*polarity(char *str, int *sign)
{
	if (str[0] == '-')
	{
		*sign = -1;
		return (str + 1);
	}
	else if (str[0] == '+')
	{
		*sign = 1;
		return (str + 1);
	}
	else
	{
		*sign = 1;
		return (str);
	}
}

static int		ft_len(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	char	*buf;
	int		i;
	int		*sign;
	int		len;
	int		result;

	if (!str || !str[0])
		return (0);
	sign = (int *)malloc(sizeof(int));
	buf = (char *)str;
	buf = polarity(ft_rm_whitespace(buf), sign);
	i = 0;
	len = ft_len(buf);
	result = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
	{
		result = result + (buf[i] - '0') * ft_power(10, len - i - 1);
		i++;
	}
	result = *sign * result;
	free(sign);
	return (result);
}