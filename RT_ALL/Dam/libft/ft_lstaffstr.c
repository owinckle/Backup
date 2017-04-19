/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaffstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 13:02:09 by dbirtel           #+#    #+#             */
/*   Updated: 2015/12/17 15:21:11 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaffstr(t_list **lst)
{
	if ((*lst)->next == NULL)
		ft_putendl((char *)(*lst)->content);
	else
	{
		ft_putendl((char *)(*lst)->content);
		ft_lstaffstr(&(*lst)->next);
	}
}
