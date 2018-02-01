/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owinckle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:45:40 by owinckle          #+#    #+#             */
/*   Updated: 2018/01/31 12:45:41 by owinckle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** External Headers
*/
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Macros
*/
# define MAX(a, b)		(b & ((a - b) >> 31)) | (a & (~(a - b) >> 31))
# define MIN(a, b)		(a & ((a - b) >> 31)) | (b & (~(a - b) >> 31))
# define ABS(a)			(a < 0) ? -a : a

/*
** Masks
*/
# define F_SHARP		(1 << 0)
# define F_SPACE		(1 << 1)
# define F_PLUS			(1 << 2)
# define F_MINUS		(1 << 3)
# define F_ZERO			(1 << 4)
# define F_WILDCARD		(1 << 5)
# define F_UPCASE		(1 << 6)
# define F_SHORT		(1 << 7)
# define F_SHORT2		(1 << 8)
# define F_LONG			(1 << 9)
# define F_LONG2		(1 << 10)
# define F_INTMAX		(1 << 11)
# define F_SIZE_T		(1 << 12)
# define F_APP_PRECI	(1 << 14)
# define F_POINTER		(1 << 15)
# define BUF_SIZE		64

/*
** Structure
*/
typedef	struct			s_env
{
	int					len;
	short				f;
	short				n;
	int					min_length;
	int					precision;
	int					padding;
	int					printed;
	va_list				ap;
	char				*format;
	unsigned			c;
	int					buffer_index;
	char				buff[BUF_SIZE];
}						t_env;

/*
** Functions
*/
int						ft_printf(const char *restrict format, ...);
void					padding(t_env *e, int n);
void					buffer(t_env *e, void *new, size_t size);

void					ftpf_putnb(t_env *e);
void					ftpf_itoa(intmax_t n, t_env *e, int len);
void					ftpf_ibasefill(uintmax_t tmp, int b, char s[BUF_SIZE],
							t_env *e);
void					ftpf_itoabase(uintmax_t n, int b, t_env *e);
void					ftpf_putnb_base(int base, t_env *e);

void					ftpf_putwchar(t_env *e, unsigned int wc, int wlen,
							int nb_bytes);
void					ftpf_putwstr(t_env *e);
void					ftpf_putstr(t_env *e);
void					ftpf_print(char *s, t_env *e);
void					ftpf_character(t_env *e, unsigned c);

void					ftpf_pt_address(t_env *e);

void					parse(t_env *e);

int						ft_strchri(char *s, int c, int i);
size_t					ft_wcharlen(unsigned wc);
int						ft_atoi(char *s);
char					*ft_strchr(const char *s, int c);
void					*ft_memcpy(void *dest, const void *src, size_t n);
size_t					ft_strlen(const char *s);
size_t					ft_wstrlen(unsigned *s);
int						ft_strchri_base(char *s, int c, int i);

#endif
