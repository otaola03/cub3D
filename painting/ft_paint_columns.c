/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:20:55 by jperez            #+#    #+#             */
/*   Updated: 2023/04/15 18:05:16 by jperez           ###   ########.fr       */
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
int	ft_get_texture_index(t_game *game, double max_angle, int orientation)
{
	if (orientation == HORIZONTAL)
		return (ft_get_texture_x(game->player[x], game->player[y], max_angle, game->map));
	else
		return (ft_get_texture_y(game->player[x], game->player[y], max_angle, game->map));
}

void	ft_paint_ceiling(t_img *img, int img_x, double wall_height, int ceiling_color)
{
	int	img_y;
	int	end;

	end	= (WIN_HEIGHT - wall_height) / 2;
	img_y = -1;
	while (++img_y < end)
		my_mlx_pixel_put(img, img_x, img_y, ceiling_color);
}

# define IMG		0
# define TEXTURE	1
void	ft_paint_wall(t_img *img, t_img *texture, int indexes[], double wall_height)
{
	int		img_y;
	int		start;
	float	scale;

	scale = texture->height / wall_height;
	start = (WIN_HEIGHT - wall_height) / 2;
	img_y = start;
	while (img_y < start + wall_height)
		my_mlx_pixel_put(img, indexes[IMG], img_y, ft_get_texture_pixel(texture, indexes[TEXTURE], (img_y++ - start) * scale));
}

void	ft_paint_floor(t_img *img, int img_x, double wall_height, int floor_color)
{
	int	img_y;

	img_y = (WIN_HEIGHT - wall_height) / 2 + wall_height;
	while (img_y < WIN_HEIGHT)
		my_mlx_pixel_put(img, img_x, img_y++, floor_color);
}

t_img	*ft_choose_texture(t_game *game, int orientation, double max_angle)
{
	if (ft_angle_in_range(0, M_PI, max_angle) && orientation == HORIZONTAL)
		return (game->no_texture);
	else if (ft_angle_in_range(M_PI, 2 * M_PI, max_angle) && orientation == HORIZONTAL)
		return (game->so_texture);
	else if (ft_angle_in_range(M_PI_2, M_PI_3_2, max_angle) && orientation == VERTICAL)
		return (game->we_texture);
	else
		return (game->ea_texture);
}

void	ft_paint_column(t_game *game, t_img *img, int img_x, double max_angle)
{
	t_colision	*colision;
	double		wall_height;
	int			indexes[2];

	colision = ft_raycasting(game->player[x], game->player[y], max_angle, game->map);
	wall_height = ft_calculate_wall_height(colision->distance);
	indexes[1] = ft_get_texture_index(game, max_angle, colision->orientation);
	indexes[0] = img_x;


	ft_paint_ceiling(img, img_x, wall_height, game->ceiling_color);

	ft_paint_wall(img, ft_choose_texture(game, colision->orientation, max_angle), indexes, wall_height);

	ft_paint_floor(img, img_x, wall_height, game->floor_color);


	//ft_edit_img(img, game, ray_x, wall_height);
	free(colision);
}
