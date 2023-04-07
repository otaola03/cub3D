/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:53:53 by jperez            #+#    #+#             */
/*   Updated: 2023/04/06 17:12:42 by jperez           ###   ########.fr       */
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


	#ifdef DEBUG
	printf("-------Horizontal-Colisions-------\n");
	#endif
	horizontal_colision = ft_horizontal_colisions(player_x, player_y, angle, map);

	#ifdef DEBUG
	printf("\n-------Vertical-Colisions-------\n");
	#endif
	vertical_colision = ft_vertical_colisions(player_x, player_y, angle, map);

	#ifdef DEBUG
	printf("\n");
	printf("Horizontal_colision: %f\n", horizontal_colision);
	printf("Vertical_colision: %f\n", vertical_colision);
	#endif

	return (ft_return_min(horizontal_colision, vertical_colision));
}
