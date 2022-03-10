/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cadran2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:42:33 by naben-za          #+#    #+#             */
/*   Updated: 2022/03/04 12:23:49 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	octan_4(t_fdf *fdf, double dx, double dy, double e)
{
	e = dx;
	dx = e * 2;
	dy *= 2;
	while (1)
	{
		my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0x0037f9);
		fdf->x -= 1;
		if ((int)fdf->x == (int)fdf->x1)
			break ;
		e += dy;
		if (e >= 0)
		{
			fdf->y += 1;
			e += dx;
		}
	}
}

void	octan_3(t_fdf *fdf, double dx, double dy, double e)
{
	e = dy;
	dy = e * 2;
	dx *= 2;
	while (1)
	{
		my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xffffff);
		fdf->y += 1;
		if ((int)fdf->y == (int)fdf->y1)
			break ;
		e += dx;
		if (e <= 0)
		{
			fdf->x -= 1;
			e += dy;
		}
	}
}

void	octan_5(t_fdf *fdf, double dx, double dy, double e)
{
	e = dx;
	dx = e * 2;
	dy *= 2;
	while (1)
	{
		my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xf600f9);
		fdf->x -= 1;
		if ((int)fdf->x == (int)fdf->x1)
			break ;
		e -= dy;
		if (e >= 0)
		{
			fdf->y -= 1;
			e += dx;
		}
	}
}

void	octan_6(t_fdf *fdf, double dx, double dy, double e)
{
	e = dy;
	dy = e * 2;
	dx *= 2;
	while (1)
	{
		my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xffffff);
		fdf->y -= 1;
		if ((int)fdf->y == (int)fdf->y1)
			break ;
		e -= dx;
		if (e >= 0)
		{
			fdf->x -= 1;
			e += dy;
		}
	}
}

void	cadran_2and3(t_fdf *fdf, double dx, double dy, double e)
{
	if (dy > 0)
	{
		if (-dx >= dy)
		{
			octan_4(fdf, dx, dy, e);
		}
		else
		{
			octan_3(fdf, dx, dy, e);
		}
	}
	else if (dy < 0)
	{
		if (dx <= dy)
		{
			octan_5(fdf, dx, dy, e);
		}
		else
		{
			octan_6(fdf, dx, dy, e);
		}
	}
	else
		horizontal_left(fdf);
}
