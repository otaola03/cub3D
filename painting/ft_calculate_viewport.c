/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_viewport.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:40:17 by jperez            #+#    #+#             */
/*   Updated: 2023/03/28 18:30:37 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static double	ft_calculate_min_angle(double angle)
{
	printf("angle - FOV / 2: %f\n", (angle - FOV / 2));
	if (angle - FOV / 2 == 0)
		return (0);
	else if (angle - FOV / 2 < 0)
		return (2 * M_PI - fabs(angle - (FOV / 2))); 
	else
		return (angle - FOV / 2);
}

static double	ft_calculate_max_angle(double angle)
{
	if (angle + FOV / 2 == 2 * M_PI)
		return (0);
	if (angle + FOV / 2 > 2 * M_PI)
		return ((angle + FOV / 2) - 2 * M_PI);
	else
		return (angle + FOV / 2);
}

void	ft_calculate_viewport(double angle, double *min_angle, double *max_angle)
{
	*min_angle = ft_calculate_min_angle(angle);
	*max_angle = ft_calculate_max_angle(angle);
}
