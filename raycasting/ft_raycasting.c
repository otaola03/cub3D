/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:53:53 by jperez            #+#    #+#             */
/*   Updated: 2023/04/02 17:12:35 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

static double	ft_return_min(double horizontal_colision, double vertical_colision)
{
	if (vertical_colision < horizontal_colision)
		return (vertical_colision);
	else
		return (horizontal_colision);
}

double	ft_raycasting(double player_x, double player_y, double angle, char **map)
{
	double	horizontal_colision;
	double	vertical_colision;


	printf("-------Horizontal-Colisions-------\n");
	horizontal_colision = ft_horizontal_colisions(player_x, player_y, angle, map);
	printf("\n");

	printf("-------Vertical-Colisions-------\n");
	vertical_colision = ft_vertical_colisions(player_x, player_y, angle, map);

	printf("Horizontal_colision: %f\n", horizontal_colision);
	printf("Vertical_colision: %f\n", vertical_colision);
	return (ft_return_min(horizontal_colision, vertical_colision));
}
