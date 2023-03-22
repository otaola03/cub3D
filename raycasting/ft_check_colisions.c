/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colisions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:04:14 by jperez            #+#    #+#             */
/*   Updated: 2023/03/22 19:08:40 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

double	ft_get_distance(double player_x, double player_y, double ray_x, double ray_y)
{
	return (sqrt(pow(ray_x - player_x, 2) + pow(ray_y - player_y, 2)));
}

int	ft_check_wall(char **map, double ray_x, double ray_y)
{
	if (map[floor(ray_y / UNIT)][floor(ray_x / UNIT)] > 0)
		return (1);
	return (0);
}



int	ft_raycasting(double player_x, double player_y, double angle)
{
	if (angle == 0 || angle == 2 * MI_PI || angle == MI_PI)
		ft_y_colisions();
	else if (angle == MI_PI_2 || angle == 3 * MI_PI_2)
		ft_x_colisiions();
	else
	{
		ft_vertical_colisions();
		ft_horiontal_colisions();
	}
}
