/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:12:50 by owinckle          #+#    #+#             */
/*   Updated: 2018/01/23 11:12:52 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

di sc oux p - Finir Xx
%% afficher pourcentage - Faire la gestion d'erreurs
#0-+ aqaq (soit espace connard)
Taille minimum de champ +/- - Fix gros nombres
Precision
hh h l ll j z

*/

#include "../includes/libftprintf.h"
#include <stdio.h>

int		ft_printf(const char * restrict format, ...)
{
	t_env	e;

	va_start(e.ap, format);
	parse((char*)format, 0, e);
	return (0);
}

int		main(int argc, char** argv)
{
	ft_printf("Salut %s, tu es le %10der! Top 10%%\n", "titi", 1);
	printf("Salut %s, tu es le %10der! Top 10%%\n", "toto", 1);
	return (0);
}