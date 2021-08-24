#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	int		i;

	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	str[len + 1] = 0;
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	free(s1);
	len = 0;
	while (s2[len] && s2[len] != '\n')
		str[i++] = s2[len++];
	if (s2[len] == '\n')
		str[i] = s2[len];
	else
		str[i] = 0;
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	str = malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
