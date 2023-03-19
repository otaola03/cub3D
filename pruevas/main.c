/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:37:18 by jperez            #+#    #+#             */
/*   Updated: 2023/03/19 19:01:12 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
#define MLX_ERROR 1


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


/*
int	ft_create_img(void *mlx, void *mlx_win, int color)
{
	t_data	*img2;

	img2 = (t_data *)malloc(sizeof(t_data));
	img2->img = mlx_new_image(mlx, 400, 400);
	img2->addr = mlx_get_data_addr(img2->img, &img2->bits_per_pixel, &img2->line_length, &img2->endian);

	int i,j;
	i = 0;
	while (i < 400)
	{
		j = 0;
		while (j < 400)
		{
			my_mlx_pixel_put(img2, i, j, 0x08E7E7);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img2->img, 40, 40);
	return (0);
}
*/

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1120, 980, "Hello world!");
	img = ft_create_img(mlx, 400, 400);
	ft_edit_img(img, 400, 400, 0xF300FF);
	mlx_put_image_to_window(mlx, mlx_win, img->mlx_img, 40, 40);
	//ft_create_img(mlx, mlx_win);

	mlx_loop(mlx);
}
