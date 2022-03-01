#include "fdf.h"

int     count_nbr(char const *s, char c)
{
	int	nbr;

	nbr = 0;
	while (*s)
	{
		if (*s != c)
		{
			nbr++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (nbr);
}

int     check_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == 32 || (line[i] >= '0' && line[i] <= '9') || line[i] == '\n' || line[i] == '-')
            ++i;
        else
        {
            ft_putstr_fd("Invalid data in file. Only numbers separated by space\n", 1);
            free(line);
            exit(EXIT_FAILURE);
        }
    }
    return (1);
}

void    ft_GetNbrAfterSplit(char **tab, t_Dlist *p_list)
{
    int     i;
    int     j;

    i = 0;
    while (i < p_list->width)
    {
        j = dlist_append(p_list, tab[i]);
        if (j == -1)
        {
            ft_free(p_list);
            exit(EXIT_FAILURE);
        }
        p_list->lenght++;
        ++i;
    }
}

void    ParseOn(t_Dlist *p_list, int fd){
    char    *line;
    char    **line_tab;
    int     count_number;
    
    line = get_next_line(fd);
    if (check_line(line) == 1)
        p_list->width = count_nbr(line, ' ');
    while (line != NULL)
    {
        if (check_line(line) == 1)
        {
            count_number = count_nbr(line, ' ');
            if (count_number == p_list->width)
            {
                line_tab = ft_split(line, ' ');
                ft_GetNbrAfterSplit(line_tab, p_list);
            }
            else
            {
                ft_putstr_fd("Numbers per line are different. It should be the same.\n", 1);
                exit(EXIT_FAILURE);
            }
            p_list->height++;
        }
        line = get_next_line(fd);
    }
}

int     **ft_fill_board(int **board, t_Dlist *p_list)
{
	int i;
	int j;

	i = 0;
	board = malloc(sizeof(board) * p_list->height);
	if (!board)
		return (0);
	while (i < p_list->height)
	{
		j = 0;
		board[i] = malloc(sizeof(board[i]) * p_list->width);
		if (!board[i])
			return (0);
		while (j < p_list->width)
		{
			board[i][j] = p_list->p_head->z;
			j++;
            p_list->p_head = p_list->p_head->p_next;
		}
		i++;
	}
	return (board);
}