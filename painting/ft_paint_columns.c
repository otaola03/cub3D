/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:20:55 by jperez            #+#    #+#             */
/*   Updated: 2023/03/30 20:10:16 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	ft_paint_column(t_mlx *mlx, int x, int wall_height)
{
	t_img *column;

	column = ft_create_img(mlx->mlx, 1, WIN_HEIGHT);
	ft_edit_img(column, 0x000000, 0xFF0000, wall_height);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, column->mlx_img, x, 0);
	free(column);
}
