/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:20:55 by jperez            #+#    #+#             */
/*   Updated: 2023/04/06 18:49:10 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	ft_paint_column(t_mlx *mlx, int x, int wall_height)
{
	t_img *column;
	int		floor_px;

	floor_px = (WIN_HEIGHT - wall_height) / 2;
	column = ft_create_img(mlx->mlx, 1, wall_height);
	ft_edit_img(column, 0x000000, 0xFF0000, wall_height);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, column->mlx_img, x, floor_px);
	free(column);
}
