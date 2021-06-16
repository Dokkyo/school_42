#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

// get_next_line.c
int		get_next_line(int fd, char **line);
int		lookfor_nl(char *line);
void	refresh_buf(char *b);

//get_next_line_utils.c
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);

#endif
