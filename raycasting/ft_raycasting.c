/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:53:53 by jperez            #+#    #+#             */
/*   Updated: 2023/03/22 20:26:49 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int	ft_raycasting(double player_x, double player_y, double angle, char **map)
{
	if (angle == 0 || angle == 2 * M_PI || angle == M_PI)
		ft_y_colisions(player_x, player_y, angle, map);
	else if (angle == M_PI_2 || angle == 3 * M_PI_2)
		ft_x_colisions(player_x, player_y, angle, map);
	else
	{
		ft_vertical_colisions(player_x, player_y, angle, map);
		ft_horizontal_colisions(player_x, player_y, angle, map);
	}
	return (0);
}
