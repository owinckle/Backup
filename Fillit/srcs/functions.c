/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opichou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:17:47 by opichou           #+#    #+#             */
/*   Updated: 2016/02/12 01:26:12 by opichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_tetros	*ft_tetr_forceadd(t_tetros **alst, t_tetros *new)
{
	t_tetros	*ptr;
	size_t		len;

	ptr = *alst;
	len = 2;
	while (ptr->next && len <= 26)
	{
		ptr = ptr->next;
		len++;
	}
	ptr->next = new;
	return (*alst);
}

t_tetros	*ft_tetro_new(char *str)
{
	t_tetros	*tmp;

	tmp = malloc(sizeof(t_tetros));
	if (!tmp)
		ft_error();
	tmp->str = str;
	tmp->pos_x = 0;
	tmp->pos_y = 0;
	tmp->next = NULL;
	return (tmp);
}

char		*ft_strndup(const char *src, size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char*)malloc((size + 1) * sizeof(char));
	if (ptr)
	{
		while (size--)
		{
			ptr[i] = src[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	else
	{
		return (0);
	}
}
