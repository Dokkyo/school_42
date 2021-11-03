#include "ft_printf.h"

void	c_conv(void)
{
	unsigned char	c;

	c = va_arg(g_ap, int);
	ft_putchar(c);
}

void	s_conv(char **str)
{
	*str = va_arg(g_ap, char *);
	if (*str == 0)
		*str = ft_strjoin("", "(null)");
	else
		*str = ft_strjoin(*str, "");
}
