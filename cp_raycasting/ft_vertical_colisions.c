/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertica_colisions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:14:12 by jperez            #+#    #+#             */
/*   Updated: 2023/03/31 17:46:26 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static	double	ft_get_ray_gap_y(double angle)
{
	if (0 < angle && angle < M_PI)
		return (0 - UNIT * tan(ft_normalize_angle(angle)));
	else
		return (UNIT * tan(ft_normalize_angle(angle)));
}

static double ft_get_ray_y(double player_y, double ray_x, double player_x, double angle)
{
	if (ft_angle_in_range(angle, 0, M_PI))
		return (player_y - (ray_x - player_x) * tan(ft_normalize_angle(angle)));
	else
		return (player_y + (ray_x - player_x) * tan(ft_normalize_angle(angle)));
}

double	ft_vertical_colisions(double player_x, double player_y,  double angle, char **map)
{
	double	ray_gap_y;
	double	ray_gap_x;
	double	ray_y;
	double	ray_x;

	printf("============= VERTICAL =============\n");
	printf("Angle: %f\n\n", angle);
	printf("Player_y: %f\n", player_y);
	printf("Player_x: %f\n", player_x);
	ft_assing_x_variable(player_x, angle, &ray_gap_x ,&ray_x);
	ray_gap_y = ft_get_ray_gap_y(angle);
	ray_y = ft_get_ray_y(player_y, ray_x, player_x, angle);
	while (!ft_check_wall(map, ray_x, ray_y))
	{
		ray_x += ray_gap_x;
		ray_y += ray_gap_y;
		printf("-----------------\n\n");
	}
	return (ft_get_distance(player_x, player_y, ray_x, ray_y));
}

