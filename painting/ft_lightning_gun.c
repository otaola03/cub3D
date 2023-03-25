/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lightning_gun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:47:24 by jperez            #+#    #+#             */
/*   Updated: 2023/03/25 14:17:48 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	ft_lightning_gun(char **map, int win_width, double angle, screen_distance)
{
	int		x;
	int		y;
	double	gap;
	double	min_angle;
	double	max_angle;

	gap = FOV / win_width;
	ft_find_pos(map, &x, &y);
	ft_calculate_viewport(angle, &min_angle, &max_angle);
	while (min_angle < max_angle)
	{
		ft_calculate_wall_height(win_width, ft_raycasting(x * UNIT, y * UNIT, \
			min_angle, map), scree_distance);
		ft_paint_column();
		min_angle += gap;
	}
}
