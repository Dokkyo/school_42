/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: naben-za <naben-za@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2022/03/02 16:05:43 by naben-za	       #+#    #+#	      */
/*   Updated: 2022/03/04 12:44:02 by naben-za         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(struct s_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	isometric(double *x, double *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - (double)z;
}

void	bresenham(int **tab, t_fdf *fdf, t_Dlist *my_list)
{
	double	z;
	double	z1;

	z = tab[(int)fdf->y][(int)fdf->x];
	z1 = tab[(int)fdf->y1][(int)fdf->x1];
	ft_zoom(my_list, fdf);
	isometric(&fdf->x, &fdf->y, z);
	isometric(&fdf->x1, &fdf->y1, z1);
	fdf->x += WIDTH / 2;
	fdf->x1 += WIDTH / 2;
	fdf->y += 50;
	fdf->y1 += 50;
	tracer_segment(fdf);
}

void	ft_draw(t_fdf *fdf, int **tab, t_Dlist *my_list)
{
	double	j;
	double	i;

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
