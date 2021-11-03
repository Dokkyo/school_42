#include "ft_printf.h"

void	di_conv(char **str)
{
	long long	nbr;
	char		*tmp;

	nbr = va_arg(g_ap, int);
	if (nbr < 0)
	{
		*str = ft_pdiuxtoa(-nbr, BASE_10);
		tmp = *str;
		*str = ft_strjoin("-", *str);
		free(tmp);
	}
	else
		*str = ft_pdiuxtoa(nbr, BASE_10);
}

void	p_conv(char **str)
{
	unsigned long long	nbr;
	char				*tmp;

	nbr = (unsigned long long)va_arg(g_ap, void *);
	*str = ft_pdiuxtoa(nbr, BASE_16_LOWER);
	tmp = *str;
	*str = ft_strjoin("0x", *str);
	free(tmp);
}

void	ux_conv(char **str, char *base)
{
	long long	nbr;

	nbr = va_arg(g_ap, unsigned int);
	*str = ft_pdiuxtoa(nbr, base);
}
