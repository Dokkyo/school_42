#ifndef FDF_H
# define FDF_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>

# define WIDTH 1920
# define HEIGHT 1080
# define TILEWIDTH 64
# define TILEHEIGHT 32

struct	s_node
{
	int				x;
	int				y;
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

/*struct	s_map
{
	int		x;
	int		y;
}		t_map;
*/
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

t_Dlist *dlist_new(void);
int     dlist_append(t_Dlist *p_list, char *nbr, int i);
void	ft_free(t_Dlist *p_list);
void    ParseOn(t_Dlist *p_list, int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    tracerSegment(void *mlx, void *mlx_win, t_data *data, int x1, int y1, int x2, int y2);


#endif