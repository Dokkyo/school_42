#include "fdf.h"

void    isometric(double *x, double *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - (double)z;
}

void    bresenham(int **tab, t_fdf *fdf, t_Dlist *my_list)
{
    double  z;
    double  z1;

    (void)my_list;
    z = tab[(int)fdf->y][(int)fdf->x];
    z1 = tab[(int)fdf->y1][(int)fdf->x1];
    ft_zoom(my_list, fdf);
    isometric(&fdf->x, &fdf->y, z);
    isometric(&fdf->x1, &fdf->y1, z1);
    fdf->x += 150;
    fdf->y += 150;
    fdf->x1 += 150;
    fdf->y1 += 150;

    tracerSegment(fdf);
}

void    ft_draw(t_fdf *fdf, int **tab, t_Dlist *my_list)
{
    double     j;
    double     i;

    j = 0;
    while (j < my_list->height)
    {
        i = 0;
        while (i < my_list->width)
        {
            if (i < my_list->width - 1)
            {
                first_bresenham(my_list, fdf, i, j);
                bresenham(tab, fdf, my_list);
            }
            if (j < my_list->height - 1)
            {
                second_bresenham(my_list, fdf, i, j);
                bresenham(tab, fdf, my_list);
            }
            ++i;
        }
        ++j;
    }
}

void    init(int **tab, t_Dlist *my_list)
{
    t_fdf   *fdf;

    fdf = malloc(sizeof(*fdf));
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Be aware - Drink water");
    fdf->img.img  = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
    fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
    fdf->x = 0;
    fdf->y = 0;
    fdf->x1 = 0;
    fdf->y1 = 0;
    ft_draw(fdf, tab, my_list);
    mlx_loop(fdf->mlx);
}

int main(int ac, char **av)
{
    t_Dlist *my_list;
    int     **tab;
    int fd;

    (void)ac;
    tab = NULL;
    my_list = dlist_new();
    fd = open(av[1], O_RDONLY);
    ParseOn(my_list, fd);
    tab = ft_fill_board(tab, my_list);
    init(tab, my_list);

    return (0);
}