/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture_y.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:49:21 by jperez            #+#    #+#             */
/*   Updated: 2023/04/08 17:53:29 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static double	ft_get_ray_x(double player_x, double angle)
{
	if (ft_angle_in_range(M_PI_2, M_PI_3_2, angle))
		return (floor(player_x / UNIT) * UNIT - 1);
	else
		return (floor(player_x / UNIT) * UNIT + UNIT);
}

static double	ft_get_ray_y(double player_y, double player_x, double ray_x, double angle)
{
	if (ft_angle_in_range(0, M_PI, angle))
		return (player_y - fabs(player_x - ray_x) * tan(ft_normalize_angle(angle)));
	else
		return (player_y + fabs(player_x - ray_x) * tan(ft_normalize_angle(angle)));
}

static void	ft_find_gap(double *ray_gap_x, double *ray_gap_y, double angle)
{
	if (ft_angle_in_range(M_PI_2, M_PI_3_2, angle))
		*ray_gap_x = 0 - UNIT;
	else
		*ray_gap_x = UNIT;
	
	if (ft_angle_in_range(0, M_PI, angle))
		*ray_gap_y = 0 - fabs(*ray_gap_x) * tan(ft_normalize_angle(angle));
	else
		*ray_gap_y = fabs(*ray_gap_x) * tan(ft_normalize_angle(angle));
}

int	ft_get_texture_y(double player_x, double player_y,  double angle, char **map)
{
	double	ray_x;
	double	ray_y;
	double	ray_gap_x;
	double	ray_gap_y;



	ray_x = ft_get_ray_x(player_x, angle);
	ray_y = ft_get_ray_y(player_y, player_x, ray_x, angle);

	ft_find_gap(&ray_gap_x, &ray_gap_y, angle);

	while (!ft_check_wall(map, ray_x, ray_y))
	{
		ray_x += ray_gap_x;
		ray_y += ray_gap_y;
	}

	return ((int)floor(ray_y) % UNIT);
}
