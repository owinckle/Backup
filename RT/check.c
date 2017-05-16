/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 23:11:22 by dbirtel           #+#    #+#             */
/*   Updated: 2017/03/30 00:53:39 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	check_block(char *line, int *balise, int count)
{
	if (*balise == B_VOID)
	{
		if (!ft_strncmp(line, "**********", 10))
			*balise = B_MAIN;
	}
	else if (*balise == B_MAIN)
	{
		if (!ft_strncmp(line, "+++ CAMERA +++", 14))
			*balise = B_CAM;
		else if (!ft_strncmp(line, "||| LIGHTS |||", 14))
			*balise = B_LIGHT;
		else if (!ft_strncmp(line, "=== OBJECTS ===", 15))
			*balise = B_OBJ;
		else if (!ft_strncmp(line, "**********", 10))
			*balise = B_VOID;
		else
			error_parsing(count, "check_block, in file check.c\n");
	}
}

void	check_line(char *line, int *balise, int count)
{
	if (*balise == B_CAM)
		if (!ft_strncmp(line, "pos_x", 5))
			*balise = 111;
	if (*balise == B_LIGHT)
		if (!ft_strncmp(line, "pos_x", 5))
			*balise = 121;
	if (*balise == B_OBJ)
		if (!ft_strncmp(line, "obj_type", 8))
			*balise = 131;
	if (*balise != 111 && *balise != 121 && *balise != 131)
		error_parsing(count, "check_line, in file check.c\n");
}

void	check_obj(char *line, int *balise, int count, t_scene *s)
{
	if (!ft_strncmp(line, "+++", 3) || !ft_strncmp(line, "|||", 3)\
			|| !ft_strncmp(line, "===", 3))
		*balise = B_MAIN;
	else if (*balise == 111)
		add_cam(line, count, s);
	else if (*balise == 121)
		add_lights(line, count, s);
	else
		add_obj(line, count, s);
}

void	check_valid(char *line, int *balise, int count, t_scene *s)
{
	if (*balise == B_VOID || *balise == B_MAIN)
		check_block(line, balise, count);
	else if (*balise == B_CAM || *balise == B_LIGHT \
			|| *balise == B_OBJ)
		check_line(line, balise, count);
	else
		check_obj(line, balise, count, s);
}
