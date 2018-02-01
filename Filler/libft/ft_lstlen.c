/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 17:13:03 by owinckle          #+#    #+#             */
/*   Updated: 2016/03/25 18:25:52 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *tmp)
{
	int		i;
	t_list	*list;

	i = 0;
	if (tmp)
	{
		list = tmp;
		while (list)
		{
			i++;
			list = list->next;
		}
	}
	return (i);
}
