#ifndef FDF_H
# define FDF_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

struct	s_node
{
	int				z;
	struct s_node	*p_next;
};

typedef struct	s_dlist
{
	int             width;
    int             height;
    int             lenght;
	struct s_node   *p_head;
    struct s_node	*p_tail;
}				t_Dlist;

struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

typedef struct	s_fdf
{
	double			x;
	double			y;
	double			x1;
	double			y1;
	void			*mlx;
	void			*mlx_win;
	struct s_data	img;
}				t_fdf;


t_Dlist *dlist_new(void);
int     dlist_append(t_Dlist *p_list, char *nbr);
void	ft_free(t_Dlist *p_list);
void    ParseOn(t_Dlist *p_list, int fd);
void	my_mlx_pixel_put(struct s_data *data, int x, int y, int color);
void    tracerSegment(t_fdf *fdf);
int		**ft_fill_board(int **board, t_Dlist *p_list);
int     ft_mod(double a);
int     ft_max(double a, double b);
void    isometric(double *x, double *y, int z);
void    bresenham(int **tab, t_fdf *fdf, t_Dlist *my_list);
void    ft_zoom(t_Dlist *my_list, t_fdf *fdf);
void    first_bresenham(t_Dlist *my_list, t_fdf *fdf, double i, double j);
void    second_bresenham(t_Dlist *my_list, t_fdf *fdf, double i, double j);


#endif