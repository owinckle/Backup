/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 14:43:22 by dbirtel           #+#    #+#             */
/*   Updated: 2016/02/03 10:00:01 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	tmp = f(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		ft_lstpushback(&new, ft_lstnew(tmp->content, tmp->content_size));
		lst = lst->next;
	}
	free(tmp);
	return (new);
}
