/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:12:49 by naben-za          #+#    #+#             */
/*   Updated: 2022/03/04 19:22:30 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

struct	s_node
{
	int				z;
	struct s_node	*p_next;
};

typedef struct s_dlist
{
	int				width;
	int				height;
	int				lenght;
	struct s_node	*p_head;
	struct s_node	*p_tail;
}			t_Dlist;

struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

typedef struct s_fdf
{
	double			x;
	double			y;
	double			x1;
	double			y1;
	void			*mlx;
	void			*mlx_win;
	struct s_data	img;
}				t_fdf;

//main.c
t_fdf	*init(void);

//parse.c
void	parse_assist(t_Dlist *p_list, int fd, char *line, char **line_tab);
t_Dlist	*parse_on(int fd);
int		**ft_fill_board(int **board, t_Dlist *p_list);

//parse_utils.c
int		count_nbr(char const *s, char c);
t_Dlist	*dlist_new(void);
void	dlist_append(t_Dlist *p_list, char *nbr);
int		count_nbr(char const *s, char c);
void	ft_getnbr(char **tab, t_Dlist *p_list);

//draw.c
void	my_mlx_pixel_put(struct s_data *data, int x, int y, int color);
void	isometric(double *x, double *y, int z);
void	bresenham(int **tab, t_fdf *fdf, t_Dlist *my_list);
void	ft_draw(t_fdf *fdf, int **tab, t_Dlist *my_list);

//draw_utils.c
int		ft_mod(double a);
int		ft_max(double a, double b);
void	ft_zoom(t_Dlist *my_list, t_fdf *fdf);
void	first_bresenham(t_Dlist *my_list, t_fdf *fdf, double i, double j);
void	second_bresenham(t_Dlist *my_list, t_fdf *fdf, double i, double j);

//free.c
void	dlist_delete(t_Dlist **p_list);
void	tabint_delete(int **board, int size);
void	tabchar_delete(char **board);
void	ft_error1(t_Dlist **p_list);
void	ft_error2(int **board, int size);

//close.c
int		ft_close(int keycode, t_fdf *fdf);
int		ft_close_mouse(t_fdf *fdf);

//bresenham.c
void	horizontal_right(t_fdf *fdf);
void	horizontal_left(t_fdf *fdf);
void	vertical_line(t_fdf *fdf, double dy);
void	tracer_segment(t_fdf *fdf);

//cadran1.c
void	octan_1(t_fdf *fdf, double dx, double dy, double e);
void	octan_2(t_fdf *fdf, double dx, double dy, double e);
void	octan_7(t_fdf *fdf, double dx, double dy, double e);
void	octan_8(t_fdf *fdf, double dx, double dy, double e);
void	cadran_1and4(t_fdf *fdf, double dx, double dy, double e);

//cadran2.c
void	octan_3(t_fdf *fdf, double dx, double dy, double e);
void	octan_4(t_fdf *fdf, double dx, double dy, double e);
void	octan_5(t_fdf *fdf, double dx, double dy, double e);
void	octan_6(t_fdf *fdf, double dx, double dy, double e);
void	cadran_2and3(t_fdf *fdf, double dx, double dy, double e);

#endif