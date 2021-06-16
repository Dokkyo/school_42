/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 12:31:47 by twagner           #+#    #+#             */
/*   Updated: 2021/03/21 16:12:25 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_sky.h"

int		ft_sum(int **board, int size, int col_row, int clue_pos)
{
	int	i;
	int	j;
	int	max;
	int	total;
	int to_check;

	i = -1;
	max = 0;
	total = 0;
	while (++i < size)
	{
		j = (clue_pos % 2 == 0) ? i : size - 1 - i;
		to_check = (clue_pos < 2) ? board[j][col_row] : board[col_row][j];
		if (to_check > max)
		{
			total++;
			max = to_check;
		}
	}
	return (total);
}

int		ft_is_board_valid(int **board, int **clues, int size)
{
	int i;
	int j;
	int	total;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < size)
		{
			total = ft_sum(board, size, j, i);
			if (total != clues[i][j])
				return (0);
		}
	}
	return (1);
}

int		ft_is_cell_valid(int **board, int **clues, int row, int col)
{
	int i;
	int	size;
	int clue_index;
	int	clue_diff;
	int	col_or_row;

	i = 0;
	size = ft_board_size(board);
	while (i < size)
	{
		if ((board[row][i] == board[row][col] && i != col)
				|| (board[i][col] == board[row][col] && i != row))
			return (0);
		i++;
	}
	i = -1;
	while (clues[++i])
	{
		clue_index = (i < 2) ? col : row;
		col_or_row = (i < 2) ? row : col;
		clue_diff = (i % 2 == 0) ? col_or_row : size - 1 - col_or_row;
		if ((size - clues[i][clue_index] + 2 + clue_diff) <= board[row][col])
			return (0);
	}
	return (1);
}

int		ft_is_success(int **board, int **clues, int col, int sc_size)
{
	int size;

	size = ft_board_size(board);
	if (col > size - 1 && sc_size == 1)
	{
		if (ft_is_board_valid(board, clues, size))
		{
			ft_print_solution(board, size);
			return (1);
		}
	}
	return (0);
}

int		ft_solver(int **board, int **clues, int col, int sc_size)
{
	int row;
	int	size;

	size = ft_board_size(board);
	if (ft_is_success(board, clues, col, sc_size) == 1)
		return (1);
	if (col > size - 1 && sc_size > 1)
	{
		sc_size--;
		col = 0;
	}
	row = -1;
	while (++row < size)
		if (board[row][col] == 0)
		{
			board[row][col] = sc_size;
			if (ft_is_cell_valid(board, clues, row, col) == 1)
			{
				if (ft_solver(board, clues, col + 1, sc_size) == 1)
					return (1);
				board[row][col] = 0;
			}
			board[row][col] = 0;
		}
	return (0);
}
