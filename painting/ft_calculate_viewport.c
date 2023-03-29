/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_viewport.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:40:17 by jperez            #+#    #+#             */
/*   Updated: 2023/03/29 18:24:54 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static double	ft_calculate_min_angle(double angle)
{
	if (angle == 0)
		return (2 * M_PI - FOV_2);
	else if (angle + FOV_2 > 2 * M_PI)
		return (angle - FOV_2);
	else if (angle - FOV_2 < 0)
		return (2 * M_PI + (angle - FOV_2));
	else
		return (angle - FOV_2);
}

static double	ft_calculate_max_angle(double angle)
{
	if (angle == 0)
		return (FOV_2);
	else if (angle + FOV_2 > 2 * M_PI)
		return (angle + FOV_2 - 2 * M_PI);
	else if (angle - FOV_2 < 0)
		return (angle + FOV_2);
	else
		return (angle + FOV_2);
}

void	ft_calculate_viewport(double angle, double *min_angle, double *max_angle)
{
	*min_angle = ft_calculate_min_angle(angle);
	*max_angle = ft_calculate_max_angle(angle);
}
