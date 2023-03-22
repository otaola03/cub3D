/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colisions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:04:14 by jperez            #+#    #+#             */
/*   Updated: 2023/03/22 20:30:47 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

double	ft_get_distance(double player_x, double player_y, double ray_x, double ray_y)
{
	return (sqrt(pow(ray_x - player_x, 2) + pow(ray_y - player_y, 2)));
}

//El error esta en que el map lo has puesto en las funciones como int
int	ft_check_wall(char **map, double ray_x, double ray_y)
{
	int	x;
	int	y;
	
	printf("map---->%d\n", map[0][0]);
	x = (int)floor(ray_y / UNIT);
	y = (int)floor(ray_x / UNIT);
	//CAmbialo pa que sea variable las formas maximas
	if (!((0 < ray_x && ray_x < UNIT * 64) && (0 < ray_y && ray_y < UNIT * 64)))
		return (1);
	printf("----------------->fff\n");
	printf("x: %d\ny: %d\n", x, y);
	if (map[x][y] > 0)
		return (1);
	return (0);
}

int	ft_angle_in_range(double angle, double start, double end)
{
	if (start < angle && angle < end)
		return (1);
	return (0);
}
