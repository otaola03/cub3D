/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:55:17 by jperez            #+#    #+#             */
/*   Updated: 2023/04/13 20:45:45 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define WIN_WIDTH			1200
# define WIN_HEIGHT			600
# define UNIT				64
# define MOVE_SPEED			25
# define ANGLE_SPEED		M_PI / 10
# define FOV				M_PI / 3
# define FOV_2				FOV / 2
# define SCREEN_DISTANCE	(WIN_WIDTH / 2) / tan(FOV / 2)
# define ANGLE_GAP			FOV / WIN_WIDTH

# define M_PI_3_2			3 * M_PI_2

# include "mlx/mlx.h" 
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "./libft/libft.h"

enum{
    A_KEY = 0,
    S_KEY = 1,
    D_KEY = 2,
    W_KEY = 13,
    LEFT_KEY = 123,
    RIGHT_KEY = 124,
    ESC_KEY = 153,
};

enum
{
	HORIZONTAL, VERTICAL,
};

enum {
	x,
	y,
	angle,
};

typedef struct s_colision
{
	double	colision_x;
	double	colision_y;
	double	distance;
	int		orientation;
}	t_colision;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	double	player_x;
	double	player_y;
	double	angle;
	int		sky;
	int		floor;
	t_img	*wall;
}	t_mlx;

typedef struct s_game{
	void		*mlx;
	void		*window;
	t_img	*no_texture;
	t_img	*ea_texture;
	t_img	*so_texture;
	t_img	*we_texture;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	double		player[3];
}	t_game;

int	ft_get_quadrant(double angle);
/*===============================================================================*/
/*									UTILS										 */
/*===============================================================================*/

/* ------------------------------- ft_manage_imgs -------------------------------*/
t_img *ft_create_img(void *mlx, int width, int height);
void	ft_edit_img(t_img *img, t_mlx *mlx, int x, int wall_height);
void	ft_create_background(t_img *img, int floor, int sky);
t_img	*ft_save_xpm(t_mlx *mlx, char *path);

/* ------------------------------- ft_create_minimap -------------------------------*/
void	ft_create_minimap(void *mlx, void *mlx_win, int width, int height);

/* ------------------------------- ft_print_map -------------------------------*/
void	ft_print_map(char **map);

/* ------------------------------- ft_save_map -------------------------------*/
char	*ft_get_next_line(int fd);
char	**ft_save_map(char *map_addr);

/* ------------------------------- ft_save_map -------------------------------*/
int	ft_args_len(char **args);

/* ------------------------------- ft_save_map -------------------------------*/
int	ft_round_number(double number);

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
double	ft_return_min(double horizontal_colision, double vertical_colision);
t_colision	*ft_raycasting(double player_x, double player_y, double angle, char **map);
double	ft_first_quadrant(double player_x, double player_y, double angle, char **map);
double	ft_second_quadrant(double player_x, double player_y, double angle, char **map);
double	ft_third_quadrant(double player_x, double player_y, double angle, char **map);
double	ft_third_quadrant(double player_x, double player_y, double angle, char **map);

/* ------------------------------- ft_create_minimap -------------------------------*/
double	ft_get_distance(double player_x, double player_y, double ray_x, double ray_y);
int	ft_check_wall(char **map, double ray_x, double ray_y);
int	ft_angle_in_range(double start, double end, double angle);

/* ------------------------------- ft_create_minimap -------------------------------*/
double	ft_normalize_angle(double angle);

/*===============================================================================*/
/*									PAINTING									 */
/*===============================================================================*/

void	ft_calculate_viewport(double angle, double *min_angle, double *max_angle);
double	ft_calculate_wall_height(double ray_distance);
void	ft_paint_column(t_game *game, t_img *img, int x, double max_angle);
void	ft_lightning_gun(char **map, double angle, t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int ft_get_texture_pixel(t_img *img, int x, int y);
t_img	*ft_create_img(void *mlx, int width, int height);

/*===============================================================================*/
/*									PAINTING									 */
/*===============================================================================*/

int	key_hook(int keycode, t_game *game);
int	ft_main_loop(t_game *game);
int	ft_get_texture_x(double player_x, double player_y,  double angle, char **map);
int	ft_get_texture_y(double player_x, double player_y,  double angle, char **map);

#endif 
