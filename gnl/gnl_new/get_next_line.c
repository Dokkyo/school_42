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
//	j = 0;
	j = ft_strlen(b);
	if (b[j] == '\n')
		++j;
	i = 0;
	while (b[i] != '\0')
		b[i++] = b[j++];
	while (b[i] != '\0')
		b[i++] = 0;
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			rbytes;
	char		*line;
//	int			i;

	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (NULL);
	rbytes = 1;
	line = ft_strdup("");
	line = ft_strjoin(line, buf);
	while (rbytes > 0 && !lookfor_nl(buf))
	{
		rbytes = read(fd, buf, BUFFER_SIZE);
//		printf("buf1: -%s- ", buf);
//		buf[rbytes] = 0;
//		printf("rbytes: -%d-\n", rbytes);
		if (rbytes)
		{
			buf[rbytes] = 0;
			line = ft_strjoin(line, buf);
		}
		else if (rbytes == -1)
			return (NULL);
		else if (rbytes == 0 && buf[0] != 0)
		{
			refresh_buf(buf);
			return (line);
		}
		else
		{
			free(line);
			line = NULL;
			return (line);
		}
		printf("line: -%s-\n", line);
	}
//	printf("buf before:%s", buf);
/*	if (lookfor_nl(buf))
	{
		i = ft_strlen(line);
		line[i] = '\n';
	}*/
	refresh_buf(buf);
	printf("buf after refresh: -%s-\n", buf);
//	printf("buf after:%s", buf);
/*	if (!lookfor_nl(buf))
	{
		i = ft_strlen(line);
		line[i] = 0;
	}*/
//	printf("%d\n", rbytes);
/*	if (rbytes == 0)
	{
		free(line);
		line = NULL;
		return (line);
	}*/
//	printf("%d", rbytes);
	return (line);
}

int main()
{
	int 	ret;
	char	*line;
	
	line = "";
	ret = open("test1.txt", O_RDONLY);
		line = get_next_line(ret);
		printf("main : %s", line);
		free(line);
		line = get_next_line(ret);
		printf("main : %s", line);
		free(line);
		line = get_next_line(ret);
		printf("main : %s", line);
		free(line);
/*		line = get_next_line(ret);
		printf("main : %s", line);
		free(line);
		line = get_next_line(ret);
		printf("main : %s", line);
		free(line);
		line = get_next_line(ret);
		printf("main : %s", line);
		free(line);
		line = get_next_line(ret);
		printf("main : %s", line);
		free(line);
		line = get_next_line(ret);
		printf("main : %s", line);
		free(line);*/

//	while (line != NULL)
//	{
//		line = get_next_line(ret);
//		printf("main %s", line);
//		free(line);
//	}
//	return (0);
}
