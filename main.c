/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:37:18 by jperez            #+#    #+#             */
/*   Updated: 2023/03/24 17:42:03 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
#define MLX_ERROR 1

/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1120, 980, "Hello world!");
	img = ft_create_img(mlx, 400, 400);
	ft_edit_img(img, 400, 400, 0xF300FF);
	mlx_put_image_to_window(mlx, mlx_win, img->mlx_img, 40, 40);
	//ft_create_img(mlx, mlx_win);

	mlx_loop(mlx);
}
*/

void	ft_find_pos(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
	}
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		x;
	int		y;
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1200, 1200, "Hello world!");
	//ft_create_minimap(mlx, mlx_win, 1200, 1200);
	//mlx_loop(mlx);
	if (argc < 2)
		return (1);
	map = ft_save_map(argv[1]);
	ft_print_map(map);
	ft_find_pos(map, &x, &y);
	printf("\nx: %d\ny: %d\n-----------------------\n\n",x ,y);
	ft_raycasting(x * UNIT, y * UNIT, M_PI / 8, map);
	return (0);
}
