/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_angle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:15:26 by jperez            #+#    #+#             */
/*   Updated: 2023/04/08 13:14:05 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

int	ft_angle_in_range(double start, double end, double angle)
{
	if (start <= angle && angle <= end)
		return (1);
	return (0);
}

/*
double	ft_normalize_angle(double angle)
{
	if (ft_angle_in_range(0, M_PI_2, angle))
		return (angle);
	if (ft_angle_in_range(M_PI_2, M_PI, angle))
		return (angle - M_PI_2);
	if (ft_angle_in_range(M_PI, M_PI_3_2, angle))
		return (angle - M_PI);
	if (ft_angle_in_range(M_PI_3_2, 2 * M_PI, angle))
		return (angle - M_PI_3_2);
	return (-1);
}
*/
double	ft_normalize_angle(double angle)
{
    // Convertir a valor positivo
    angle = fmod(fabs(angle), 2*M_PI);
    
    // Reducir al primer cuadrante
    if (angle<= M_PI/2) {
        return angle;
    } else if (angle <= M_PI) {
        return M_PI - angle;
    } else if (angle <= 3*M_PI/2) {
        return angle - M_PI;
    } else {
        return 2*M_PI - angle;
    }
}

int	ft_get_quadrant(double angle)
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
