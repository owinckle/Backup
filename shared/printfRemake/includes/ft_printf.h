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
# define MAX(a, b)		b & ((a - b) >> 31) | a & (~(a - b) >> 31)
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
typedef	struct	s_env
{
	int			len;
	short		f;
	short		n;
	int			min_length;
	int			precision;
	int			padding;
	int			printed;
	va_list		ap;
	char		*format;
	unsigned	c;
	int			buffer_index;
	char		buff[BUF_SIZE];
}				t_env;

/*
** Functions
*/
int		ft_printf(const char * restrict format, ...);
void	padding(t_env *e, int n);
void	buffer(t_env *e, void *new, size_t size);

void	ftpf_putnb(t_env *e);
void	ftpf_itoabase(intmax_t n, t_env *e, int len);
void	ftpf_ibasefill(uintmax_t tmp, int b, char s[BUF_SIZE], t_env *e);


void	parse(t_env *e);

int		ft_strchri(char *s, int c, int i);
int		ft_atoi(char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif