#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define	BASE_10			"0123456789"
# define	BASE_16_LOWER	"0123456789abcdef"
# define	BASE_16_UPPER	"0123456789ABCDEF"

va_list	g_ap;

// ft_printf.c
int		ft_printf(const char *fmt, ...);

// utils.c
void	ft_putchar(char c);
size_t	ft_strlen(char const *str);
void	ft_putstr(char *s);
char	*ft_strjoin(char const *s1, char const *s2);

// anytoa.c
char	*ft_pdiuxtoa(unsigned long long n, char *base);

// conversions.c
void	c_conv(void);
void	s_conv(char **str);

// conversions_nbrs.c
void	di_conv(char **str);
void	p_conv(char **str);
void	ux_conv(char **str, char *base);

#endif
