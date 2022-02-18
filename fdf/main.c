#include "fdf.h"

int     main(int ac, char **av)
{
    int     fd;
    t_Dlist *my_list;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int     i = 0;
    int     j = 0;

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
            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + WIDTH / 2, ((i + j) * (32 / 2)) + HEIGHT / 2 - (my_list->p_head->z * 32),
            ((i - j) * (64 /2)) + (WIDTH / 2) + (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - (my_list->p_head->z * 32));

            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + WIDTH / 2 + (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - (my_list->p_head->z * 32),
            ((i - j) * (64 /2)) + WIDTH / 2, ((i + j) * (32 / 2)) + HEIGHT / 2 + 32 - (my_list->p_head->z * 32));

            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + (WIDTH / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 - (my_list->p_head->z * 32),
             ((i - j) * (64 /2)) + (WIDTH / 2) - (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - (my_list->p_head->z * 32));

            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + (WIDTH / 2) - (64 / 2) + 2, ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - (my_list->p_head->z * 32),
             ((i - j) * (64 /2)) + WIDTH / 2 + 2, ((i + j) * (32 / 2)) + HEIGHT / 2 + 32 - (my_list->p_head->z * 32));
            
            // left
            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + WIDTH / 2, ((i + j) * (32 / 2)) + HEIGHT / 2 - (my_list->p_head->z * 32),
            ((i - j) * (64 /2)) + (WIDTH / 2) + (64 / 2) - (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) + (32 / 2) - (my_list->p_head->z * 32));

            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + WIDTH / 2 + (64 / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + (32 / 2) - (my_list->p_head->z * 32),
            ((i - j) * (64 /2)) + WIDTH / 2, ((i + j) * (32 / 2)) + HEIGHT / 2 + 32 - (my_list->p_head->z * 32));

            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + (WIDTH / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + 32 - (my_list->p_head->z * 32),
             ((i - j) * (64 /2)) + (WIDTH / 2), ((i + j) * (32 / 2)) + HEIGHT / 2 + 32);

            tracerSegment(mlx, mlx_win, &img, ((i - j) * (64 /2)) + (WIDTH / 2) + 2, ((i + j) * (32 / 2)) + HEIGHT / 2 + 32,
             ((i - j) * (64 /2)) + WIDTH / 2 + 2 - 64 / 2, ((i + j) * (32 / 2)) + HEIGHT / 2 + 32 / 2);


            ++i;
            my_list->p_head = my_list->p_head->p_next;
        }
        ++j;
    }
    mlx_loop(mlx);

    /*while (i < my_list->height)
    {
        tracerSegment(mlx, mlx_win, &img, 50, 50 + j, 50 + (PIXEL_SPACE * my_list->width), 50 + j);
        j += PIXEL_SPACE;
        ++i;
    }
    i = 0;
    j = 0;
    while (i <= my_list->width)
    {
        tracerSegment(mlx, mlx_win, &img, 50 + j, 50, 50 + j, 50 + (PIXEL_SPACE * (my_list->height - 1)));
        j += PIXEL_SPACE;
        ++i;
    }*/

    while (my_list->p_head != NULL)
    {
        printf("x=%d y=%d z=%d\n", my_list->p_head->x, my_list->p_head->y, my_list->p_head->z);
        my_list->p_head = my_list->p_head->p_next;
    }
    printf("\nwidth=%d\nheight=%d.", my_list->width, my_list->height);
    
    return (0);
}