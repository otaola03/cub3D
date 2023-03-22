/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:55:17 by jperez            #+#    #+#             */
/*   Updated: 2023/03/21 17:29:15 by jperez           ###   ########.fr       */
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

#endif 
