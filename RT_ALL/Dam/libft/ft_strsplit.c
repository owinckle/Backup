/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirtel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:00:01 by dbirtel           #+#    #+#             */
/*   Updated: 2016/10/25 23:47:16 by dbirtel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_tok(char const *s, char c)
{
	size_t	nb_occ;
	char	*token_next;

	nb_occ = 0;
	if (!(token_next = ft_strchr(s, c)))
		return (1);
	while (*s && token_next)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			token_next = ft_strchr(s, c);
			s += (token_next) ? token_next - s : 0;
			nb_occ++;
		}
	}
	return (nb_occ);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**big_array;
	size_t		i;
	size_t		nb_tok;
	char const	*token;
	char const	*tok_next;

	big_array = NULL;
	if ((token = s))
	{
		nb_tok = count_tok(s, c);
		if ((big_array = (char**)malloc((nb_tok + 1) * sizeof(char*))))
		{
			i = 0;
			big_array[nb_tok] = NULL;
			while ((tok_next = ft_strchr(token, c)))
			{
				if (tok_next - token > 0)
					big_array[i++] = ft_strsub(s, token - s, tok_next - token);
				token = tok_next + 1;
			}
			if ((tok_next = ft_strchr(token, '\0')) - token > 0)
				big_array[i++] = ft_strsub(s, token - s, tok_next - token);
		}
	}
	return (big_array);
}
