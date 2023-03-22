/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assing_xy_variables.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:17:01 by jperez            #+#    #+#             */
/*   Updated: 2023/03/22 19:17:30 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	ft_assing_y_variable(double player_y, double angle, double *ray_gap_y, double *ray_y)
{
	if (ft_angle_in_range(angle, 0, M_PI))
	{
		*ray_gap_y = 0 - UNIT;
		*ray_y = (floor(player_y / UNIT) * UNIT) - 1; 
	}
	else
	{
		*ray_gap_y = UNIT;
		*ray_y = (floor(player_y / UNIT) * UNIT) + UNIT;
	}
}

void	ft_assing_x_variable(double player_x, double angle, double *ray_gap_x, double *ray_x)
{
	if (ft_angle_in_range(angle, M_PI_2, 3 * M_PI_2))
	{
		*ray_gap_x = 0 - UNIT;
		*ray_x = (floor(player_x / UNIT) * UNIT) - 1; 
	}
	else
	{
		*ray_gap_x = UNIT;
		*ray_x = (floor(player_x / UNIT) * UNIT) + UNIT;
	}
}
