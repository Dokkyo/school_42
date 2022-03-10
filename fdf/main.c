/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: naben-za <naben-za@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2022/03/02 15:05:14 by naben-za	       #+#    #+#	      */
/*   Updated: 2022/03/04 14:20:46 by naben-za         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(*fdf));
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	fdf->x = 0;
	fdf->y = 0;
	fdf->x1 = 0;
	fdf->y1 = 0;
	return (fdf);
}

int	main(int ac, char **av)
{	
	int		**tab;
	int		fd;
	t_Dlist	*my_list;
	t_fdf	*fdf;

	if (ac == 2)
	{
		tab = NULL;
		fd = open(av[1], O_RDONLY);
		my_list = parse_on(fd);
		tab = ft_fill_board(tab, my_list);
		fdf = init();
		ft_draw(fdf, tab, my_list);
		tabint_delete(tab, my_list->height);
		dlist_delete(&my_list);
		mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img.img, 0, 0);
		mlx_hook(fdf->mlx_win, 33, 1L << 17, ft_close_mouse, fdf);
		mlx_hook(fdf->mlx_win, 2, 1L << 0, ft_close, fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
