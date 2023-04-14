/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:37:18 by jperez            #+#    #+#             */
/*   Updated: 2023/04/14 18:31:21 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


/*
int	main(void)
{
	void	*mlx;
	void	*window;
	t_img	*img;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1120, 980, "Hello world!");
	img = ft_create_img(mlx, 400, 400);
	ft_edit_img(img, 400, 400, 0xF300FF);
	mlx_put_image_to_window(mlx, window, img->mlx_img, 40, 40);
	//ft_create_img(mlx, window);

	mlx_loop(mlx);
}
*/

void	ft_find_pos(char **map, double *x, double *y)
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
				*x = j * UNIT + 32;
				*y = i * UNIT + 32;
			}
	}
}


int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		return (1);
	game= (t_game *)malloc(sizeof(t_game));
	game->map = ft_save_map(argv[1]);
	game->player[angle] = 0;

	ft_print_map(game->map);
	ft_find_pos(game->map, &game->player[x], &game->player[y]);
	printf("\nx: %f\ny: %f\n-----------------------\n\n", game->player[x] ,game->player[y]);

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	game->floor_color = 0x000000;
	game->ceiling_color = 0xFF0000;



	game->no_texture = ft_save_xpm(game, "./img_cub.xpm");
	ft_lightning_gun(game->map, game->player[angle], game);



	mlx_hook(game->window, 2, (1L << 1), key_hook, game);
	//mlx_loop_hook(mlx->mlx, ft_main_loop, mlx);
	//ft_lightning_gun(mlx->map, mlx->angle, mlx);
	mlx_loop(game->mlx);
	return (0);
}
