#include <stdlib.h>
#include <time.h>
#include "minilibx-linux/mlx.h"

int	main(void)
{
	int		h = 700, w = 1200;
	int		y, x;
	void	*mlx_connection;
	void	*mlx_window;

	y = h * 0.1;
	x = w * 0.1;
	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, 1200, 700, "r3tnuh-007");
	//mlx_loop(mlx_connection);
	srand(time(NULL));
	while (y <= h * 0.9)
	{
		while (x <= w * 0.9)
		{
			if (x % 2 == 0)
				mlx_pixel_put(mlx_connection, mlx_window,x ++, y, rand());
			else
				mlx_pixel_put(mlx_connection, mlx_window,x ++, y, rand() % 1000000);
		}
		y ++;
		x = w * 0.1;
	}
	mlx_string_put(mlx_connection, mlx_window, 1100, 680, rand() % 1000000, "r3tnuh-007");
	mlx_loop(mlx_connection);
	return (0);
}
