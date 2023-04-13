/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:20:55 by jperez            #+#    #+#             */
/*   Updated: 2023/04/10 20:14:08 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	ft_put_texture_pixel(t_img *src_img, t_img *dst_img, int x, int y)
{
	char *src;
	char *dst;

	src = src_img->addr + (y * src_img->line_len + x * (src_img->bpp / 8));
	dst = dst_img->addr + (y * dst_img->line_len + x * (dst_img->bpp / 8));
	dst = src;
}

//int	ft_get_pixel

void	ft_paint_column(t_mlx *mlx, t_img *img, int x, double max_angle)
{
	int	texture_x;
	int	texture_y;
	double	wall_height;

	wall_height = ft_calculate_wall_height(ft_raycasting(\
		mlx->player_x, mlx->player_y, max_angle, mlx->map));
	#ifdef DEBUG
	printf("Wall_height: %f\n", wall_height);
	printf("\n------------Painnt-Commun------------\n");
	#endif
	texture_x = ft_get_texture_x(mlx->player_x, mlx->player_y, max_angle, mlx->map);
	texture_y = ft_get_texture_y(mlx->player_x, mlx->player_y, max_angle, mlx->map);

	#ifdef DEBUG
	printf("texture_x: %d\n", texture_x);
	printf("texture_y: %d\n", texture_y);
	#endif
	ft_edit_img(img, mlx, x, wall_height);
}
