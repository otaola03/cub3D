/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lightning_gun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:47:24 by jperez            #+#    #+#             */
/*   Updated: 2023/04/13 19:45:39 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	*ft_send_height_and_angle(double wall_height, double angle)
{
	double	*output;

	output = (double *)malloc(sizeof(double) * 2);
	if (!output)
		exit(-1);
	output[0] = wall_height;
	output[1] = angle;
	return (output);
}

void	ft_lightning_gun(char **map, double angle, t_game *game)
{
	int		x;
	double	wall_height;
	double	min_angle;
	double	max_angle;
	t_img	*img;

	ft_calculate_viewport(angle, &min_angle, &max_angle);
	x = 0;
	mlx_clear_window(game->mlx, game->window);
	img = ft_create_img(game->mlx, WIN_WIDTH, WIN_HEIGHT);

	#ifdef DEBUG
	printf("min: %f\nmax: %f\n", min_angle, max_angle);
	#endif

	while (x < WIN_WIDTH)
	{
		#ifdef DEBUG
		printf("==============================================\n");
		printf("		RAY: %d					 \n", x);
		printf("==============================================\n");
		printf("Angle: %f\n", max_angle);
		printf("Normalize-angle: %f\n", ft_normalize_angle(max_angle));
		printf("Player_x: %f\n", game->player[x]);
		printf("Player_y: %f\n\n", game->player[y]);
		#endif


		/*
		wall_height = ft_calculate_wall_height(ft_raycasting(\
			mlx->player_x, mlx->player_y, max_angle, mlx->map));
		printf("Wall_height: %f\n", wall_height);
		*/

		ft_paint_column(game, img, x, max_angle);

		//ft_edit_img(img, mlx, x, wall_height);


		max_angle -= ANGLE_GAP;
		if (max_angle < 0)
			max_angle += 2 * M_PI;


		x++;
		#ifdef DEBUG
		printf("\n\n\n\n");
		#endif
	}
	mlx_put_image_to_window(game->mlx, game->window, img->mlx_img, 0, 0);
	free(img);
}
