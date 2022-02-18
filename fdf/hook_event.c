#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"
#include "libft/libft.h"
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode/*, t_vars *vars*/)
{
	printf("%d\n", keycode);
	return 0;
}

int mouse_win(int x, int y, void *p)
{
	(void)p;
	printf("%dx%d.\n", x, y);
	return 0;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, MotionNotify, PointerMotionMask, mouse_win, 0);
	mlx_loop(vars.mlx);

	return (0);
}
