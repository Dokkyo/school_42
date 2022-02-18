/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naben-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:19:01 by naben-za          #+#    #+#             */
/*   Updated: 2021/11/14 20:53:07 by naben-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	i = 50, j = 50;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Be aware - Drink water");
	img.img = mlx_new_image(mlx, 800, 600);

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 80, 80, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 81, 80, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 82, 80, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 83, 80, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 84, 80, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	my_mlx_pixel_put(&img, 80, 80, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 80, 81, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 80, 82, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 80, 83, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 80, 84, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	my_mlx_pixel_put(&img, 80, 84, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 81, 84, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 82, 84, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 83, 84, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 84, 84, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	my_mlx_pixel_put(&img, 84, 80, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 84, 81, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 84, 82, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 84, 83, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	my_mlx_pixel_put(&img, 84, 84, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	while (i < 80)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, i++, j);
	}
	while (j < 80)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, i, j++);
	}
	while (--i > 50)
	{
		my_mlx_pixel_put(&img, i, j, 0x0000FF00);
		mlx_put_image_to_window(mlx, mlx_win, img.img, i, j);
	}
	while (--j > 50)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, i, j);
	}
	mlx_loop(mlx);
	return (0);
}
