#include "ft_printf.h"

static int	len_nb(unsigned long long n, unsigned int base_len)
{
	unsigned int		i;
	unsigned long long	nb;

	i = 1;
	nb = n;
	while (nb >= base_len)
	{
		i++;
		nb = nb / base_len;
	}
	return (i);
}

char	*ft_pdiuxtoa(unsigned long long n, char *base)
{
	char	*str;
	int		len;
	int		base_len;

	base_len = (unsigned int)ft_strlen(base);
	len = len_nb(n, base_len);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	while (--len >= 0)
	{
		str[len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
