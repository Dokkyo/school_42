#include "fdf.h"

int     ft_mod(double a)
{
    if (a < 0)
        return (-a);
    else
        return (a);
}

int     ft_max(double a, double b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

void    ft_zoom(t_Dlist *my_list, t_fdf *fdf)
{
    double  a;

    a = 20;
    while (my_list->width * a >= WIDTH || my_list->height * a >= HEIGHT)
        --a;
    fdf->x *= a;
    fdf->y *= a;
    fdf->x1 *= a;
    fdf->y1 *= a;
}

void    first_bresenham(t_Dlist *my_list, t_fdf *fdf, double i, double j)
{
    if (i < my_list->width - 1)
    {
        fdf->x = i;
        fdf->x1 = fdf->x + 1;
        fdf->y = j;
        fdf->y1 = fdf->y;
    }
}

void    second_bresenham(t_Dlist *my_list, t_fdf *fdf, double i, double j)
{
    if (j < my_list->height - 1)
    {
        fdf->x = i;
        fdf->x1 = fdf->x;
        fdf->y = j;
        fdf->y1 = fdf->y + 1;
    }
}