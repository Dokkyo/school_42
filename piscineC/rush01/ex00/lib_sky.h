#ifndef lib_sky
# define lib_sky

int		ft_sum(int **board, int size, int col_row, int clue_pos);
int		ft_is_board_valid(int **board, int **clues, int size);
int		ft_is_cell_valid(int **board, int **clues, int row, int col);
int		ft_is_success(int **board, int **clues, int col, int sc_size);
int		ft_solver(int **board, int **clues, int col, int sc_size);
int		ft_board_size(int **board);
void	ft_putchar(char c);
void	ft_print_solution(int **board, int size);

#endif
