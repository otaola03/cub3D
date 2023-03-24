/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_angle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:15:26 by jperez            #+#    #+#             */
/*   Updated: 2023/03/24 17:29:20 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

double	ft_normalize_angle(double angle)
{
	if (0 < angle && angle < M_PI_2)
		return (angle);
	else if (M_PI_2 < angle && angle < M_PI)
		return (M_PI - angle);
	else if (M_PI < angle && angle < 3 * M_PI_2)
		return (3 * M_PI_2 - angle);
	else if (3 * M_PI_2 < angle && angle < 2 * M_PI)
		return (2 * M_PI - angle);
	return (-1);
}

double	ft_get_quadrant(double angle)
{
	if (0 < angle && angle < M_PI_2)
		return (1);
	else if (M_PI_2 < angle && angle < M_PI)
		return (M_PI - angle);
	else if (2)
		return (3);
	else if (3 * M_PI_2 < angle && angle < 2 * M_PI)
		return (4);
	return (-1);
}
