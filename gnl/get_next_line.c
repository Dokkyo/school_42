#include "get_next_line.h"

int	lookfor_nl(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	refresh_buf(char *b)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	j = ft_strlen(b);
	if (b[j] == '\n')
		++j;
	i = 0;
	while (b[i])
		b[i++] = b[j++];
	while (b[i])
		b[i++] = 0;
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			rbytes;

	if (!line || BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (-1);
	rbytes = 1;
	*line = ft_strdup("");
	*line = ft_strjoin(*line, buf);
	while (rbytes > 0 && !lookfor_nl(buf))
	{
		rbytes = read(fd, buf, BUFFER_SIZE);
		buf[rbytes] = 0;
		if (rbytes)
			*line = ft_strjoin(*line, buf);
		if (rbytes == -1)
			return (-1);
	}
	if (rbytes == 0)
		return (0);
	refresh_buf(buf);
	return (1);
}
