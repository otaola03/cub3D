/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_colisions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:06:04 by jperez            #+#    #+#             */
/*   Updated: 2023/04/01 19:05:27 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static double	ft_get_ray_gap_x(double angle)
{
	if (M_PI_2 < angle && angle < 3 * M_PI_2)
		return (0 - UNIT / tan(ft_normalize_angle(angle)));
	else
		return (UNIT / tan(ft_normalize_angle(angle)));
}

static double	ft_get_ray_x(double player_x, double player_y, double ray_y, double angle)
{
	if (ft_angle_in_range(angle, M_PI, 3 * M_PI_2))
		return (player_x - (player_y - ray_y) / tan(ft_normalize_angle(angle)));
	else
		return (player_x + (player_y - ray_y) / tan(ft_normalize_angle(angle)));
}

double	ft_horizontal_colisions(double player_x, double player_y,  double angle, char **map)
{
	double	ray_gap_y;
	double	ray_gap_x;
	double	ray_y;
	double	ray_x;

	printf("============ HORIZOTAL ===========\n");
	printf("Angle: %f\n\n", angle);
	printf("Player_y: %f\n", player_y);
	printf("Player_x: %f\n", player_x);

	ft_assing_y_variable(player_y, angle, &ray_gap_y, &ray_y);
	ray_gap_x = ft_get_ray_gap_x(angle);
	ray_x = ft_get_ray_x(player_x, player_y, ray_y, angle);
	while (!ft_check_wall(map, ray_x, ray_y))
	{
		ray_x += ray_gap_x;
		ray_y += ray_gap_y;
		printf("-----------------\n\n");
	}
	return (ft_get_distance(player_x, player_y, ray_x, ray_y));
}
