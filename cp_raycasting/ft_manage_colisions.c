/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_colisions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:05:07 by jperez            #+#    #+#             */
/*   Updated: 2023/03/31 17:18:27 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

//Cruces verticales sin inclinacion
double	ft_y_colisions(double player_x, double player_y,  double angle, char **map)
{
	double	ray_gap_y;
	double	ray_gap_x;
	double	ray_y;
	double	ray_x;

	ft_assing_x_variable(player_x, angle, &ray_gap_x ,&ray_x);
	ray_y = player_y;
	ray_gap_y = 0;
	while (!ft_check_wall(map, ray_x, ray_y))
	{
		ray_x += ray_gap_x;
		ray_y += ray_gap_y;
		printf("----------\n\n");
	}
	return (ft_get_distance(player_x, player_y, ray_x, ray_y));
}

//Cruces horizontales sin inclinacion
double	ft_x_colisions(double player_x, double player_y,  double angle, char **map)
{
	double	ray_gap_y;
	double	ray_gap_x;
	double	ray_y;
	double	ray_x;

	ft_assing_y_variable(player_y, angle, &ray_gap_y ,&ray_y);
	ray_x = player_x;
	ray_gap_x = 0;
	while (!ft_check_wall(map, ray_x, ray_y))
	{
		ray_x += ray_gap_x;
		ray_y += ray_gap_y;
		printf("-----------------\n\n");
	}
	return (ft_get_distance(player_x, player_y, ray_x, ray_y));
}
