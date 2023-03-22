/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_colisions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:05:07 by jperez            #+#    #+#             */
/*   Updated: 2023/03/22 19:12:18 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

float	ft_horizontal_colisions(double player_x, double player_y,  angle, char **map)
{
	double	ray_gap_y;
	double	ray_gap_x;
	double	ray_y;
	double	ray_x;

	if (ft_angle_in_range(angle, 0, M_PI))
	{
		ray_gap_y = 0 - UNIT;
		ray_y = (floor(player_y / UNIT) * UNIT) - 1; 
	}
	else
	{
		ray_gap_y = UNIT;
		ray_y = (floor(player_y / UNIT) * UNIT) + UNIT;
	}
	if (M_PI_2 < angle && angle < 3 * M_PI_2)
		ray_gap_x = 0 - UNIT / tan(ft_normalize_angle(angle));
	else
		ray_gap_x = UNIT / tan(ft_normalize_angle(angle));
	ray_x = player_x + (ray_y - player_y) / tan(ft_normalize_angle(angle));
	while (!ft_check_wall(map, ray_x, ray_y))
	{
		ray_x += ray_gap_x;
		ray_y += ray_gap_y;
	}
	return (ft_get_distance(ray_x, ray_y));
}

float	ft_vertical_colisions(double player_x, double player_y,  angle, char **map)
{
	double	ray_gap_y;
	double	ray_gap_x;
	double	ray_y;
	double	ray_x;

	if (ft_angle_in_range(angle, M_PI_2, 3 * M_PI_2))
	{
		ray_gap_x = 0 - UNIT;
		ray_x = (floor(player_x / UNIT) * UNIT) - 1; 
	}
	else
	{
		ray_gap_x = UNIT;
		ray_x = (floor(player_x / UNIT) * UNIT) + UNIT;
	}
	if (0 < angle && angle < M_PI)
		ray_gap_y = 0 - UNIT / tan(ft_normalize_angle(angle));
	else
		ray_gap_y = UNIT / tan(ft_normalize_angle(angle));
	ray_y = player_y + (ray_x - player_x) * tan(ft_normalize_angle(angle));
	while (!ft_check_wall(map, ray_x, ray_y))
	{
		ray_x += ray_gap_x;
		ray_y += ray_gap_y;
	}
	return (ft_get_distance(ray_x, ray_y));
}

void	ft_y_colisions()
{
	if (ft_angle_in_range(angle, 0, M_PI))
}
