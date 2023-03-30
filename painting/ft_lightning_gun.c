/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lightning_gun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:47:24 by jperez            #+#    #+#             */
/*   Updated: 2023/03/30 17:40:58 by jperez           ###   ########.fr       */
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
	printf("----------->%f\n", ANGLE_GAP);
	printf("=====================PAINTINGG==============================\n");
	x = 0;
	printf("FOV / 2: %f\n", FOV / 2);
	printf("min: %f\nmax: %f\n", min_angle, max_angle);
	printf("2PI - FOV / 2: %f\n", 2 * M_PI - FOV / 2);
	while (x < WIN_WIDTH)
	{
		printf("Angle: %f\n", min_angle);
		wall_height = ft_calculate_wall_height(ft_raycasting(\
			mlx->player_x * UNIT + 34, mlx->player_y * UNIT + 34, min_angle, mlx->map));
		ft_paint_column(mlx, x, ft_round_number(wall_height));
		min_angle += ANGLE_GAP;
		if (min_angle > 2 * M_PI)
			min_angle -= 2 * M_PI;
		x++;
		printf("\n\n\n\n");
	}
}
