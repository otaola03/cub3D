/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:37:18 by jperez            #+#    #+#             */
/*   Updated: 2023/04/02 17:34:24 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


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
				*x = j;
				*y = i;
			}
	}
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc < 2)
		return (1);
	mlx= (t_mlx *)malloc(sizeof(t_mlx));
	mlx->map = ft_save_map(argv[1]);
	ft_print_map(mlx->map);
	ft_find_pos(mlx->map, &mlx->player_x, &mlx->player_y);
	printf("\nx: %f\ny: %f\n-----------------------\n\n", mlx->player_x ,mlx->player_y);

	//ft_lightning_gun(mlx->map, M_PI_2, mlx);
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	ft_lightning_gun(mlx->map, 0, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
