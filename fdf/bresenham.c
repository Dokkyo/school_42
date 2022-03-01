#include "fdf.h"

void    tracerSegment(t_fdf *fdf)
{
    double     dx;
    double     dy;
    double     e;

    dx = fdf->x1 - fdf->x;
    if (dx != 0)
    {
        if (dx > 0)
        {
            dy = fdf->y1 - fdf->y;
            if (dy > 0) // Vecteur oblique dans le 1er cadran
            {
                if (dx >= dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 1er octan
                {
                    e = dx;
                    dx = e * 2;
                    dy *= 2;
                    while (1)
                    {
                        my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xff2d00);
                        mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                        fdf->x += 1;
                        if ((int)fdf->x == (int)fdf->x1)
                            break;
                        e = e - dy;
                        if (e < 0)
                        {
                            fdf->y += 1;
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
                        my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xffffff);
                        mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                        fdf->y += 1;
                        if ((int)fdf->y == (int)fdf->y1)
                            break;
                        e = e - dx;
                        if (e < 0)
                        {
                            fdf->x += 1;
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
                        my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xfff200);
                        mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                        fdf->x += 1;
                        if ((int)fdf->x == (int)fdf->x1)
                            break;
                        e += dy;
                        if (e < 0)
                        {
                            fdf->y = fdf->y - 1;
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
                        my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xffffff);
                        mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                        fdf->y -= 1;
                        if ((int)fdf->y == (int)fdf->y1)
                            break;
                        e = e + dx;
                        if (e > 0)
                        {
                            fdf->x += 1;
                            e += dy;
                        }
                    }
                }
            }
            else // dy = 0 (et dx > 0)
            {
                while ((int)fdf->x != (int)fdf->x1)
                {
                    my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0x00ff24);
                    mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                    fdf->x += 1;
                }
            }
        }
        else
        {
            dy = fdf->y1 - fdf->y;
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
                            my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0x0037f9);
                            mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                            fdf->x -= 1;
                            if ((int)fdf->x == (int)fdf->x1)
                                break;
                            e += dy;
                            if (e >= 0)
                            {
                                fdf->y += 1;
                                e += dx;
                            }
                        }
                    }
                    else // vecteur oblique proche de la verticale, dans le 3e octant
                    {
                        e = dy;
                        dy = e * 2;
                        dx *= 2;
                        while (1)
                        {
                            my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xffffff);
                            mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                            fdf->y += 1;
                            if ((int)fdf->y == (int)fdf->y1)
                                break;
                            e += dx;
                            if (e <= 0)
                            {
                                fdf->x -= 1;
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
                            my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xf600f9);
                            mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                            fdf->x -= 1;
                            if ((int)fdf->x == (int)fdf->x1)
                                break;
                            e -= dy;
                            if (e >= 0)
                            {
                                fdf->y -= 1;
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
                            my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xffffff);
                            mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                            fdf->y -= 1;
                            if ((int)fdf->y == (int)fdf->y1)
                                break;
                            e -= dx;
                            if (e >= 0)
                            {
                                fdf->x -= 1;
                                e += dy;
                            }
                        }
                    }
                }
            }
            else // dy = 0 (et dx < 0)
            {
                while ((int)fdf->x != (int)fdf->x1)
                {
                    my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0x00ff24);
                    mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                    fdf->x -= 1;
                }
            }
        }
    }
    else
    {
        dy = fdf->y1 - fdf->y;
        if (dy != 0)
        {
            if (dy > 0)
            {
                while (fdf->y != fdf->y1)
                {
                    my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xf97400);
                    mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                    fdf->y += 1;
                }
            }
            else
            {
                while (fdf->y != fdf->y1)
                {
                    my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xf97400);
                    mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
                    fdf->x -= 1;
                }
            }
        }
    }
}