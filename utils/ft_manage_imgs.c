/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:41:56 by jperez            #+#    #+#             */
/*   Updated: 2023/03/20 13:27:54 by jperez           ###   ########.fr       */
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

void	ft_edit_img(t_img *img, int width, int height, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			if ((0 <= x && x < WIDTH) || (0 <= y && y < WIDTH) || (width - WIDTH < x && x < width) || (height- WIDTH < y && y < height))
				my_mlx_pixel_put(img, x, y, 0xC5FF00);
			else
				my_mlx_pixel_put(img, x, y, color);
		}
	}
}
