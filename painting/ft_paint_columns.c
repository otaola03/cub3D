/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:20:55 by jperez            #+#    #+#             */
/*   Updated: 2023/04/14 17:56:02 by jperez           ###   ########.fr       */
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
int	ft_get_texture_index(t_mlx *mlx, double max_angle, int orientation)
{
	if (orientation == HORIZONTAL)
		return (ft_get_texture_x(mlx->player_x, mlx->player_y, max_angle, mlx->map));
	else
		return (ft_get_texture_y(mlx->player_x, mlx->player_y, max_angle, mlx->map));
}

void	ft_paint_sky(t_img *img, int img_x, double wall_height, int sky_color)
{
	int	img_y;
	int	end;

	end	= (WIN_HEIGHT - wall_height) / 2;
	img_y = -1;
	while (++img_y < end)
		my_mlx_pixel_put(img, img_x, img_y, sky_color);
}

void	ft_paint_floor(t_img *img, int img_x, double wall_height, int floor_color)
{
	int	img_y;

	img_y = (WIN_HEIGHT - wall_height) / 2 + wall_height;
	while (img_y < WIN_HEIGHT)
		my_mlx_pixel_put(img, img_x, img_y++, floor_color);
}

void	ft_paint_wall(t_img *img, t_img *texture, int img_x, double wall_height, int texture_x)
{
	int		img_y;
	int		start;
	float	scale;

	scale = texture->height / wall_height;
	start = (WIN_HEIGHT - wall_height) / 2;
	img_y = start;
	while (img_y < start + wall_height)
		my_mlx_pixel_put(img, img_x, img_y, ft_get_texture_pixel(texture, texture_x, (img_y - start) * scale));
}


void	ft_paint_column(t_mlx *mlx, t_img *img, int x, double max_angle)
{
	t_colision	*colision;
	int		texture_index;
	double	wall_height;

	colision = ft_raycasting(mlx->player_x, mlx->player_y, max_angle, mlx->map);
	wall_height = ft_calculate_wall_height(colision->distance);
	texture_index = ft_get_texture_index(mlx, max_angle, colision->orientation);

	#ifdef DEBUG
	printf("Wall_height: %f\n", wall_height);
	printf("\n------------Painnt-Commun------------\n");
	#endif


	#ifdef DEBUG
	printf("texture_x: %d\n", texture_x);
	printf("texture_y: %d\n", texture_y);
	#endif
	//ft_paint_sky(img, x, wall_height, mlx->sky);
	//ft_paint_wall(img, mlx->wall, x, wall_height, texture_index);
	//ft_paint_sky(img, x, wall_height, mlx->sky);
	ft_edit_img(img, mlx, x, wall_height);
	free(colision);
}
