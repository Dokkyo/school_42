/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <naben-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:11:14 by naben-za          #+#    #+#             */
/*   Updated: 2022/03/02 16:18:28 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	horizontal_right(t_fdf *fdf)
{
	while ((int)fdf->x != (int)fdf->x1)
	{
		my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0x00ff24);
		fdf->x += 1;
	}
}

void	horizontal_left(t_fdf *fdf)
{
	while ((int)fdf->x != (int)fdf->x1)
	{
		my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0x00ff24);
		fdf->x -= 1;
	}
}

void	vertical_line(t_fdf *fdf, double dy)
{
	if (dy > 0)
	{
		while (fdf->y != fdf->y1)
		{
			my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xf97400);
			fdf->y += 1;
		}
	}
	else
	{
		while (fdf->y != fdf->y1)
		{
			my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xf97400);
			fdf->y -= 1;
		}
	}
}

void	tracer_segment(t_fdf *fdf)
{
	double	dx;
	double	dy;
	double	e;

	dx = fdf->x1 - fdf->x;
	dy = fdf->y1 - fdf->y;
	e = 0;
	if (dx != 0)
	{
		if (dx > 0)
		{
			cadran_1and4(fdf, dx, dy, e);
		}
		else
		{
			cadran_2and3(fdf, dx, dy, e);
		}
	}
	else
	{
		if (dy != 0)
			vertical_line(fdf, dy);
	}
}
