#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <fcntl.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

// get_next_line.c
char	*get_next_line(int fd);
int		lookfor_nl(char *line);
void	refresh_buf(char *b);

//get_next_line_utils.c
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s);

#endif
