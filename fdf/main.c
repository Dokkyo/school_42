#include "fdf.h"

int     main(int ac, char **av)
{
    int     fd;
    t_Dlist *my_list;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    double  i = 0;
    double  j = 0;

    (void)ac;
    my_list = dlist_new();
    fd = open(av[1], O_RDONLY);
    ParseOn(my_list, fd);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Be aware - Drink water");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    while (j < my_list->height)
    {
        i = 0;
        while (i < my_list->width)
        {
            // top
            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + WIDTH / 2, ((i + j) * (32 / 2)) + HEIGHT / 2 - my_list->p_head->z,
            ((i - j) * (64 /2)) + (WIDTH / 2) + (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - my_list->p_head->z);

            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + WIDTH / 2 + (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - my_list->p_head->z,
            ((i - j) * (64 /2)) + WIDTH / 2, ((i + j) * (32 / 2)) + HEIGHT / 2 + 32 - my_list->p_head->z);

            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + (WIDTH / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 - my_list->p_head->z,
             ((i - j) * (64 /2)) + (WIDTH / 2) - (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - my_list->p_head->z);

            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + (WIDTH / 2) - (64 / 2) + 2, ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - my_list->p_head->z,
             ((i - j) * (64 /2)) + WIDTH / 2 + 2, ((i + j) * (32 / 2)) + HEIGHT / 2 + 32 - my_list->p_head->z);
            
            if (my_list->p_head->z != 0)
            {
                // left 
                tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + (WIDTH / 2) - (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - my_list->p_head->z,
                ((i - j) * (64 /2)) + (WIDTH / 2) - (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2));
                // right
                tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + (WIDTH / 2) + (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - my_list->p_head->z,
                ((i - j) * (64 /2)) + (WIDTH / 2) + (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2));

            }

            ++i;
            my_list->p_head = my_list->p_head->p_next;
        }
        ++j;
    }

    mlx_loop(mlx);
    return (0);
}