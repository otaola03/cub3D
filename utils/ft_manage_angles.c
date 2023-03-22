/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_angle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:15:26 by jperez            #+#    #+#             */
/*   Updated: 2023/03/22 16:48:18 by jperez           ###   ########.fr       */
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
}

double	ft_get_quadrant(double angle)
{
	if (0 < angle && angle < M_PI_2)
		return (1);
	else if (MI_P_2 < angle && angle < M_PI)
		return (M_PI - angle);
	else if (2)
		return (3);
	else if (3 * M_PI_2 < angle && angle < 2 * M_PI)
		return (4);
}
