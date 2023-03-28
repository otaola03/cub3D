/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lightning_gun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:47:24 by jperez            #+#    #+#             */
/*   Updated: 2023/03/28 19:35:55 by jperez           ###   ########.fr       */
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
	printf("=====================PAINTINGG==============================\n");
	x = 0;
	printf("FOV / 2: %f\n", FOV / 2);
	printf("min: %f\nmax: %f\n", min_angle, max_angle);
	printf("2PI - FOV / 2: %f\n", 2 * M_PI - FOV / 2);
	/*
	while (x < WIN_HEIGHT)
	{
		wall_height = ft_calculate_wall_height(ft_raycasting(\
			mlx->player_x * UNIT, mlx->player_y * UNIT, min_angle, mlx->map));
		ft_paint_column(mlx, x, ft_round_number(wall_height));
		min_angle += ANGLE_GAP;
		x++;
	}
	*/
}
