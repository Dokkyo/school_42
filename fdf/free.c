/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:45:56 by naben-za          #+#    #+#             */
/*   Updated: 2022/03/04 14:20:31 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dlist_delete(t_Dlist **p_list)
{
	struct s_node	*p_temp;
	struct s_node	*p_del;

	if (p_list != NULL)
	{
		p_temp = (*p_list)->p_head;
		while (p_temp)
		{
			p_del = p_temp;
			p_temp = p_temp->p_next;
			free(p_del);
		}
		free(*p_list);
	}
}

void	tabint_delete(int **board, int size)
{
	int	i;

	if (board != NULL)
	{
		i = 0;
		while (i < size)
		{
			free(board[i]);
			i++;
		}
		free(board);
		board = NULL;
	}
}

void	tabchar_delete(char **board)
{
	int	i;

	if (board != NULL)
	{
		i = 0;
		while (board[i] != NULL)
		{
			free(board[i]);
			i++;
		}
		free(board);
		board = NULL;
	}
}

void	ft_error2(int **board, int size)
{
	tabint_delete(board, size);
	ft_putstr_fd("Error.\n", 1);
	exit(0);
}

void	ft_error1(t_Dlist **p_list)
{
	dlist_delete(p_list);
	ft_putstr_fd("Error.\n", 1);
	exit(0);
}
