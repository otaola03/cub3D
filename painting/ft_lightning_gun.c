/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lightning_gun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:47:24 by jperez            #+#    #+#             */
/*   Updated: 2023/04/03 16:59:59 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	ft_lightning_gun(char **map, double angle, t_mlx *mlx)
{
	int		x;
	double	wall_height;
	double	min_angle;
	double	max_angle;

	ft_calculate_viewport(angle, &min_angle, &max_angle);
	x = 0;
	printf("min: %f\nmax: %f\n", min_angle, max_angle);
	while (x < WIN_WIDTH)
	{
		printf("==============================================\n");
		printf("		RAY: %d					 \n", x);
		printf("==============================================\n");
		printf("Angle: %f\n", max_angle);
		printf("Player_x: %f\n", mlx->player_x);
		printf("Player_y: %f\n\n", mlx->player_y);



		wall_height = ft_calculate_wall_height(ft_raycasting(\
			mlx->player_x, mlx->player_y, max_angle, mlx->map));
		printf("Wall_height: %f\n", wall_height);



		ft_paint_column(mlx, x, ft_round_number(wall_height));


		max_angle -= ANGLE_GAP;
		/*
		if (min_angle > 2 * M_PI)
			min_angle -= 2 * M_PI;
			*/
		if (max_angle < 0)
			max_angle += 2 * M_PI;


		x++;
		printf("\n\n\n\n");
	}
}
