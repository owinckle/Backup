/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:29:06 by owinckle          #+#    #+#             */
/*   Updated: 2018/01/23 11:29:07 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_env
{
	va_list			ap;
}					t_env;

/*
** Utils
*/
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
char	*ft_itoa_base(int value, int base);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

/*
** Parse
*/
int		parse_att(char *s, int i);
void	parse(char *s, int i, t_env e);

/*
** Print_Args
*/
int		print_args(char *s, int i, t_env *e, int type);
int		print_width(char *s, int i, t_env *e);

#endif
