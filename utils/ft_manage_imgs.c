/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:41:56 by jperez            #+#    #+#             */
/*   Updated: 2023/03/28 17:12:48 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

# define WIDTH 2

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

t_img *ft_create_img(void *mlx, int width, int height)
{
	t_img *img;

	img = (t_img *)malloc(sizeof(t_img));
	img->mlx_img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	return (img);
}

void	ft_edit_img(t_img *img, int floor, int sky, int wall_height)
{
	int	x;
	int	y;
	int	floor_px;

	floor_px = (WIN_HEIGHT - wall_height) / 2;
	printf("WIN_HEIGHT: %d\n", WIN_HEIGHT);
	printf("wall_height: %d\n", wall_height);
	printf("(WIN_HEIGHT - wall_height) / 2: %d\n", floor_px);
	y = -1;
	while (++y < floor_px)
		my_mlx_pixel_put(img, 0, y, floor);
	printf("y: %d\n", y);
	while (y < floor_px + wall_height)
	{
		//printf("->y: %d\n", y);
		my_mlx_pixel_put(img, 0, y++, 0x29C9DF);
	}
	printf("y: %d\n", y);
	while (y < WIN_HEIGHT)
		my_mlx_pixel_put(img, 0, y++, sky);
	printf("y: %d\n", y);
}
