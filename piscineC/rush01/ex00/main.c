/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 09:46:13 by twagner           #+#    #+#             */
/*   Updated: 2021/03/21 13:34:23 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib_sky.h"

int		ft_control_param(char *str, int num)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(str);
	if (size != num * 8 - 1)
		return (0);
	while (str[i])
	{
		if ((i % 2 == 0 && (str[i] < '1' || str[i] > '0' + num))\
				|| (i % 2 == 1 && str[i] != ' '))
			return (0);
		i++;
	}
	size = size - size / 2;
	return (size);
}

int		**ft_fill_clue_tabs(int **clues, char *values, int size)
{
	int i;
	int j;

	i = 0;
	clues = malloc(sizeof(clues) * 5);
	if (!clues)
		return (0);
	while (i < 4)
	{
		j = 0;
		clues[i] = malloc(sizeof(clues[i]) * size);
		if (!clues[i])
			return (0);
		while (j < size)
		{
			clues[i][j] = *values - 48;
			values = values + 2;
			j++;
		}
		i++;
	}
	clues[4] = NULL;
	return (clues);
}

int		**ft_fill_board(int **board, int size)
{
	int i;
	int j;

	i = 0;
	board = malloc(sizeof(board) * size + 1);
	if (!board)
		return (0);
	while (i < size)
	{
		j = 0;
		board[i] = malloc(sizeof(board[i]) * size);
		if (!board[i])
			return (0);
		while (j < size)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	board[i] = NULL;
	return (board);
}

void	ft_free_malloc(int **board, int **clues, int size)
{
	int i;

	i = 0;
	while (i < 5)
		free(clues[i++]);
	i = 0;
	while (i < size)
		free(board[i++]);
	free(clues);
	free(board);
}

int		main(int argc, char **argv)
{
	int	**clues;
	int	**board;
	int	size;

	clues = NULL;
	board = NULL;
	if (argc == 2)
	{
		size = ft_control_param(argv[1], 4) / 4;
		if (size > 0)
		{
			board = ft_fill_board(board, size);
			clues = ft_fill_clue_tabs(clues, argv[1], size);
			if (!board || !clues)
				return (0);
			if (ft_solver(board, clues, 0, size) == 0)
				ft_putstr("Error\n");
			ft_free_malloc(board, clues, size);
		}
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}
