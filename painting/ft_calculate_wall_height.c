/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_wall_height.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:07:37 by jperez            #+#    #+#             */
/*   Updated: 2023/03/29 18:31:43 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

double	ft_calculate_wall_height(double ray_distance)
{
	printf("===================WALL_HEIGHT=================\n");
	printf("ray_distance: %f\n", ray_distance);
	printf("SCREEN_DISTANCE: %f\n", SCREEN_DISTANCE);
	printf("UNIT / ray_distance * SCREEN_DISTANCE: %f\n\n", (UNIT / ray_distance) * SCREEN_DISTANCE);
	return((UNIT / ray_distance) * SCREEN_DISTANCE);
}
