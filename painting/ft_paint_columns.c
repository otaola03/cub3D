/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:20:55 by jperez            #+#    #+#             */
/*   Updated: 2023/04/08 17:57:00 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	ft_paint_column(t_mlx *mlx, t_img *img, int x, int wall_height)
{
	int	texture_x;
	int	texture_y;

	texture_x = ft_get_texture_x(mlx->player_x, mlx->player_y, mlx->angle, mlx->map);
	texture_y = ft_get_texture_y(mlx->player_x, mlx->player_y, mlx->angle, mlx->map);
//	printf("texture_x: %d\n", texture_x);
	//printf("texture_y: %d\n", texture_y);
}
