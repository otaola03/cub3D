/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:53:53 by jperez            #+#    #+#             */
/*   Updated: 2023/03/30 20:15:03 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static double	ft_return_min(double vertical_colision, double horizontal_colision)
{
	if (vertical_colision < horizontal_colision)
		return (vertical_colision);
	else
		return (horizontal_colision);
}

double	ft_raycasting(double player_x, double player_y, double angle, char **map)
{
	if (angle == 0 || angle == 2 * M_PI || angle == M_PI)
		return (ft_y_colisions(player_x, player_y, angle, map));
	else if (angle == M_PI_2 || angle == 3 * M_PI_2)
		return (ft_x_colisions(player_x, player_y, angle, map));
	else
		return (ft_return_min(ft_vertical_colisions(player_x, player_y, angle, map), \
			ft_horizontal_colisions(player_x, player_y, angle, map)));
	return (-1);
}
