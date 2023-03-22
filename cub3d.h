/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:55:17 by jperez            #+#    #+#             */
/*   Updated: 2023/03/22 20:09:52 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define UNIT	64

# include "mlx/mlx.h" 
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

/*===============================================================================*/
/*									UTILS										 */
/*===============================================================================*/

/* ------------------------------- ft_manage_imgs -------------------------------*/
t_img *ft_create_img(void *mlx, int width, int height);
void	ft_edit_img(t_img *img, int width, int height, int color);

/* ------------------------------- ft_create_minimap -------------------------------*/
void	ft_create_minimap(void *mlx, void *mlx_win, int width, int height);

/*===============================================================================*/
/*									RAYCASTING									 */
/*===============================================================================*/

/* ------------------------------- ft_create_minimap -------------------------------*/
double	ft_horizontal_colisions(double player_x, double player_y,  double angle, char **map);
double	ft_vertical_colisions(double player_x, double player_y,  double angle, char **map);
double	ft_y_colisions(double player_x, double player_y,  double angle, char **map);
double	ft_x_colisions(double player_x, double player_y,  double angle, char **map);

/* ------------------------------- ft_create_minimap -------------------------------*/
void	ft_assing_y_variable(double player_y, double angle, double *ray_gap_y, double *ray_y);
void	ft_assing_x_variable(double player_x, double angle, double *ray_gap_x, double *ray_x);

/* ------------------------------- ft_create_minimap -------------------------------*/
int	ft_raycasting(double player_x, double player_y, double angle, char **map);

/* ------------------------------- ft_create_minimap -------------------------------*/
double	ft_get_distance(double player_x, double player_y, double ray_x, double ray_y);
int	ft_check_wall(char **map, double ray_x, double ray_y);
int	ft_angle_in_range(double angle, double start, double end);

/* ------------------------------- ft_create_minimap -------------------------------*/
double	ft_normalize_angle(double angle);

#endif 
