/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:37:18 by jperez            #+#    #+#             */
/*   Updated: 2023/03/22 20:26:26 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

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

char **ft_create_map()
{
	int		i;
	int		j;
	char	**map;

	map = (char **)malloc(sizeof(char *) * 20);
	i = -1;
	while(map[++i])
		map[i] = (char *)malloc(sizeof(char) * 20);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (i == 0 || i == 19 || j == 0 || j == 19)
				map[i][j] = 1;
			else
				map[i][j] = 0;

		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1200, 1200, "Hello world!");
	//ft_create_minimap(mlx, mlx_win, 1200, 1200);
	//mlx_loop(mlx);
	
	map = ft_create_map();
	ft_raycasting(300, 400, 2 * M_PI / 3, map);
}
