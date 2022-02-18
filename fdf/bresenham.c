#include "fdf.h"

void    tracerSegment(void *mlx, void *mlx_win, t_data *data, int x1, int y1, int x2, int y2)
{
    int     dx;
    int     dy;
    int     e;

    dx = x2 - x1;
    if (dx != 0)
    {
        if (dx > 0)
        {
            dy = y2 - y1;
            if (dy > 0) // Vecteur oblique dans le 1er cadran
            {
                if (dx >= dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 1er octan
                {
                    e = dx;
                    dx = e * 2;
                    dy *= 2;
                    while (1)
                    {
                        my_mlx_pixel_put(data, x1, y1, 0xff2d00);
                        mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                        x1 += 1;
                        if (x1 == x2)
                            break;
                        e = e - dy;
                        if (e < 0)
                        {
                            y1 += 1;
                            e = e + dx;
                        }
                    }
                }
                else // vecteur oblique proche de la verticale, dans le 2d octant
                {
                    e = dy;
                    dy = e * 2;
                    dx *= 2;
                    while (1)
                    {
                        my_mlx_pixel_put(data, x1, y1, 0xffffff);
                        mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                        y1 += 1;
                        if (y1 == y2)
                            break;
                        e = e - dx;
                        if (e < 0)
                        {
                            x1 += 1;
                            e = e + dy;
                        }
                    }
                }
            }
            else if (dy < 0) // Vecteur oblique dans le 4e cadran
            {
                if (dx >= -dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 8e octant
                {
                    e = dx;
                    dx = e * 2;
                    dy *= 2;
                    while (1)
                    {
                        my_mlx_pixel_put(data, x1, y1, 0xfff200);
                        mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                        x1 += 1;
                        if (x1 == x2)
                            break;
                        e += dy;
                        if (e < 0)
                        {
                            y1 = y1 - 1;
                            e += dx;
                        }
                    }
                }
                else // vecteur oblique proche de la verticale, dans le 7e octant
                {
                    e = dy;
                    dy = e * 2;
                    dx *= 2;
                    while (1)
                    {
                        my_mlx_pixel_put(data, x1, y1, 0xffffff);
                        mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                        y1 -= 1;
                        if (y1 == y2)
                            break;
                        e = e + dx;
                        if (e > 0)
                        {
                            x1 += 1;
                            e += dy;
                        }
                    }
                }
            }
            else // dy = 0 (et dx > 0)
            {
                while (x1 != x2)
                {
                    my_mlx_pixel_put(data, x1, y1, 0x00ff24);
                    mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                    x1 += 1;
                }
            }
        }
        else
        {
            dy = y2 - y1;
            if (dy != 0)
            {
                if (dy > 0) // vecteur oblique dans le 2d cadran
                {
                    if (-dx >= dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 4e octant
                    {
                        e = dx;
                        dx = e * 2;
                        dy *= 2;
                        while (1)
                        {
                            my_mlx_pixel_put(data, x1, y1, 0x0037f9);
                            mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                            x1 -= 1;
                            if (x1 == x2)
                                break;
                            e += dy;
                            if (e >= 0)
                            {
                                y1 += 1;
                                e += dx;
                            }
                        }
                    }
                    else // vecteur oblique proche de la verticale, dans le 3e octant*
                    {
                        e = dy;
                        dy = e * 2;
                        dx *= 2;
                        while (1)
                        {
                            my_mlx_pixel_put(data, x1, y1, 0xffffff);
                            mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                            y1 += 1;
                            if (y1 == y2)
                                break;
                            e += dx;
                            if (e <= 0)
                            {
                                x1 -= 1;
                                e += dy;
                            }
                        }
                    }
                }
                else // vecteur oblique dans le 3e cadran
                {
                    if (dx <= dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 5e octant
                    {
                        e = dx;
                        dx = e * 2;
                        dy *= 2;
                        while (1)
                        {
                            my_mlx_pixel_put(data, x1, y1, 0xf600f9);
                            mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                            x1 -= 1;
                            if (x1 == x2)
                                break;
                            e -= dy;
                            if (e >= 0)
                            {
                                y1 -= 1;
                                e += dx;
                            }
                        }
                    }
                    else // vecteur oblique proche de la verticale, dans le 6e octant
                    {
                        e = dy;
                        dy = e * 2;
                        dx *= 2;
                        while (1)
                        {
                            my_mlx_pixel_put(data, x1, y1, 0xffffff);
                            mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                            y1 -= 1;
                            if (y1 == y2)
                                break;
                            e -= dx;
                            if (e >= 0)
                            {
                                x1 -= 1;
                                e += dy;
                            }
                        }
                    }
                }
            }
            else // dy = 0 (et dx < 0)
            {
                while (x1 != x2)
                {
                    my_mlx_pixel_put(data, x1, y1, 0x00ff24);
                    mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                    x1 -= 1;
                }
            }
        }
    }
    else
    {
        dy = y2 - y1;
        if (dy != 0)
        {
            if (dy > 0)
            {
                while (y1 != y2)
                {
                    my_mlx_pixel_put(data, x1, y1, 0xf97400);
                    mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                    y1 += 1;
                }
            }
            else
            {
                while (y1 != y2)
                {
                    my_mlx_pixel_put(data, x1, y1, 0xf97400);
                    mlx_put_image_to_window(mlx, mlx_win, data->img, 0, 0);
                    y1 -= 1;
                }
            }
        }
    }
}