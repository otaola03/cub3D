/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colisions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:04:14 by jperez            #+#    #+#             */
/*   Updated: 2023/04/10 20:17:56 by jperez           ###   ########.fr       */
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
	
	x = (int)floor(ray_x / UNIT);
	y = (int)floor(ray_y / UNIT);

	#ifdef DEBUG
	printf("X: %d\n", x);
	printf("Y: %d\n", y);
	#endif

	if (!((0 <= x && x < ft_strlen(map[0])) && (0 <= y && y < ft_args_len(map))))
		return (1);
	if ('0' < map[y][x] && map[y][x] <= '9')
		return (1);
	return (0);
}
