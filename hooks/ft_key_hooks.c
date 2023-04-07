/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:53:37 by jperez            #+#    #+#             */
/*   Updated: 2023/04/05 19:17:55 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	ft_move(t_mlx *mlx)
{
	mlx->player_x += cos(mlx->angle) * 10;
	mlx->player_y += sin(mlx->angle) * 10;
}

void	ft_rotate(t_mlx *mlx, int keycode)
{
	if (keycode == LEFT_KEY)
		mlx->angle += ANGLE_SPEED;
	else if (keycode == RIGHT_KEY)
		mlx->angle -= ANGLE_SPEED;

	if (mlx->angle >= 2 * M_PI)
		mlx->angle -= 2 * M_PI;
	else if (mlx->angle < 0)
		mlx->angle += 2 * M_PI;
}

int	ft_main_loop(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	ft_lightning_gun(mlx->map, mlx->angle, mlx);
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == A_KEY || keycode == S_KEY || keycode == D_KEY || keycode == W_KEY)
		ft_move(mlx);
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
		ft_rotate(mlx, keycode);
	ft_lightning_gun(mlx->map, mlx->angle, mlx);
	return (0);
}
