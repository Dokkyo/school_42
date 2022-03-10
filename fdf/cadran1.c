/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   cadran1.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: naben-za <naben-za@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2022/03/02 16:23:49 by naben-za	       #+#    #+#	      */
/*   Updated: 2022/03/02 16:33:49 by naben-za         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "fdf.h"

void	octan_1(t_fdf *fdf, double dx, double dy, double e)
{
	e = dx;
	dx = e * 2;
	dy *= 2;
	while (1)
	{
		my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xff2d00);
		fdf->x += 1;
		if ((int)fdf->x == (int)fdf->x1)
			break ;
		e = e - dy;
		if (e < 0)
		{
			fdf->y += 1;
			e = e + dx;
		}
	}
}

void	octan_2(t_fdf *fdf, double dx, double dy, double e)
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
		e = e - dx;
		if (e < 0)
		{
			fdf->x += 1;
			e = e + dy;
		}
	}
}

void	octan_8(t_fdf *fdf, double dx, double dy, double e)
{
	e = dx;
	dx = e * 2;
	dy *= 2;
	while (1)
	{
		my_mlx_pixel_put(&fdf->img, (int)fdf->x, (int)fdf->y, 0xfff200);
		fdf->x += 1;
		if ((int)fdf->x == (int)fdf->x1)
			break ;
		e += dy;
		if (e < 0)
		{
			fdf->y = fdf->y - 1;
			e += dx;
		}
	}
}

void	octan_7(t_fdf *fdf, double dx, double dy, double e)
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
		e = e + dx;
		if (e > 0)
		{
			fdf->x += 1;
			e += dy;
		}
	}
}

void	cadran_1and4(t_fdf *fdf, double dx, double dy, double e)
{
	if (dy > 0)
	{
		if (dx >= dy)
		{
			octan_1(fdf, dx, dy, e);
		}
		else
		{
			octan_2(fdf, dx, dy, e);
		}
	}
	else if (dy < 0)
	{
		if (dx >= -dy)
		{
			octan_8(fdf, dx, dy, e);
		}
		else
		{
			octan_7(fdf, dx, dy, e);
		}
	}
	else
		horizontal_right(fdf);
}
