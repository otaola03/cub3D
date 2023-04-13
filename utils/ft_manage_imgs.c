/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:41:56 by jperez            #+#    #+#             */
/*   Updated: 2023/04/10 17:29:13 by jperez           ###   ########.fr       */
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

t_img	*ft_save_xpm(t_mlx *mlx, char *path)
{
	int	width;
	int	height;
	t_img	*img;


	img = (t_img *)malloc(sizeof(t_img));
	img->mlx_img = mlx_xpm_file_to_image(mlx->mlx, path, &width, &height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
}

void	ft_edit_img(t_img *img, t_mlx *mlx, int x, int wall_height)
{
	int	y;
	int	floor_px;

	//floor_px = (WIN_HEIGHT - wall_height) / 2;
	y = -1;
	/*
	while (++y < wall_height)
		my_mlx_pixel_put(img, 0, y, 0x607CEF);
		*/
	floor_px = (WIN_HEIGHT - wall_height) / 2;
	while (++y < floor_px)
		my_mlx_pixel_put(img, x, y, mlx->floor);
	while (y < floor_px + wall_height)
	{
		//printf("->y: %d\n", y);
		my_mlx_pixel_put(img, x, y++, 0x607CEF);
	}
	while (y < WIN_HEIGHT)
		my_mlx_pixel_put(img, x, y++, mlx->sky);
}
