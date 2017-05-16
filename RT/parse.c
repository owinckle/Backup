/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 00:31:45 by dbirtel           #+#    #+#             */
/*   Updated: 2017/04/10 09:32:04 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_num(char *line, int pass)
{
	int		i;

	i = 0;
	while (pass > 0)
	{
		if (ft_isdigit(line[i]) && ft_isspace(line[i + 1]))
			--pass;
		i++;
	}
	return (ft_atof(line + i));
}

t_coord	get_coord(char *line, int start)
{
	t_coord	coord;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-' || ft_isdigit(line[i]))
			if (i == 0 || ft_isspace(line[i - 1]))
			{
				if (start > 0)
					--start;
				else
					break ;
			}
		i++;
	}
	coord.x = get_num(line + i, 0);
	coord.y = get_num(line + i, 1);
	coord.z = get_num(line + i, 2);
	return (coord);
}

void	check_num(char *line, int count)
{
	int		i;
	int		dot;

	i = 0;
	dot = 0;
	while (line[++i] && !ft_isspace(line[i]))
	{
		if (!ft_isdigit(line[i]))
		{
			if (line[i] == '.' && ft_isdigit(line[i + 1]))
			{
				if (dot == 1)
					error_parsing(count, "check_num, 1st iteration, parse.c\n");
				else
					dot = 1;
			}
			else
				error_parsing(count, "check_num, 2nd iteration, parse.c\n");
		}
	}
}

void	count_num(char *line, int num, int count)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			if (i == 0 || ft_isspace(line[i - 1]))
			{
				check_num((line + i), count);
				--num;
			}
		}
		else
		{
			if (!ft_isspace(line[i]) && line && line[i] != '.')
				error_parsing(count, "count_num, 1st iteration, parse.c\n");
		}
	}
	if (num != 0)
		error_parsing(count, "count_num, 2nd iteration, in file parse.c\n");
}
