/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_wall_height.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:07:37 by jperez            #+#    #+#             */
/*   Updated: 2023/04/02 19:26:08 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

double	ft_calculate_wall_height(double ray_distance)
{
	double	output;

	printf("Ray_distance: %f\n", ray_distance);
	output = (UNIT / ray_distance) * SCREEN_DISTANCE;
	/*
	if (output > WIN_HEIGHT)
		return (WIN_HEIGHT);
		*/
	return(output);
}
