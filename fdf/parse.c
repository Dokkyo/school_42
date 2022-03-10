/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:30:08 by naben-za          #+#    #+#             */
/*   Updated: 2022/03/10 10:08:09 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_assist(t_Dlist *p_list, int fd, char *line, char **line_tab)
{
	int		count_number;

	while (line != NULL)
	{
		count_number = count_nbr(line, ' ');
		if (count_number == p_list->width)
		{
			line_tab = ft_split(line, ' ');
			ft_getnbr(line_tab, p_list);
			free(line);
			tabchar_delete(line_tab);
		}
		else
		{
			free(line);
			ft_error1(&p_list);
		}
		p_list->height++;
		line = get_next_line(fd);
	}
}

t_Dlist	*parse_on(int fd)
{
	char	*line;
	char	**line_tab;
	t_Dlist	*p_list;

	line_tab = NULL;
	line = get_next_line(fd);
	if (line)
	{
		p_list = dlist_new();
		p_list->width = count_nbr(line, ' ');
		parse_assist(p_list, fd, line, line_tab);
	}
	else
	{
		ft_putstr_fd("Error.\n", 1);
		exit(0);
	}
	return (p_list);
}

int	**ft_fill_board(int **board, t_Dlist *p_list)
{
	int				i;
	int				j;
	struct s_node	*tmp;

	tmp = p_list->p_head;
	i = 0;
	board = malloc(sizeof(board) * p_list->height);
	if (!board)
		return (0);
	while (i < p_list->height)
	{
		j = 0;
		board[i] = malloc(sizeof(board[i]) * p_list->width);
		if (!board[i])
			ft_error2(board, p_list->height);
		while (j < p_list->width)
		{
			board[i][j] = tmp->z;
			j++;
			tmp = tmp->p_next;
		}
		i++;
	}
	return (board);
}
