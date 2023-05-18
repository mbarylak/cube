/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:34:54 by davgarci          #+#    #+#             */
/*   Updated: 2023/05/18 20:03:05 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "gnl/get_next_line.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

extern int worldmap[mapWidth][mapHeight];

typedef struct s_map {
	char	*dir;
	int		width;
	int		height;
	int		max_alt;
	char	**map;
}	t_map;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		multiplicator;
	int		multi_z;
	int		win_w;
	int		win_h;
	int		size_x;
	int		size_y;
	double	posX;//= 22; 
	double	posY;//= 12;  //x and y start position
	double	dirX;//= -1;
	double	dirY;//= 0; //initial direction vector
	double	teta;
	double	planeX;// = 0;
	double	planeY;// = 0.66; //the 2d raycaster version of camera plane
	t_image	texN;
	t_image	texS;
	t_image	texE;
	t_image	texO;
	int			x;
	int			y;
	t_map map;
}	t_mlx;

/* ERROR_MSG */

int		error_msg(int i);

/* GET_MAP_INFO */

int		get_map_info(char *file, t_mlx *mlx);
void	get_map(char *file, t_mlx *mlx);

/* PARSER */

void	cube_init(char *file, t_mlx *mlx);

void	fdf_init(t_mlx *mlx);
int	hook_exit(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int	ft_input(int keycode, t_mlx *mlx);
void raycasting(t_mlx *mlx);
void	vertical_texture(int x, int drawStart, int drawEnd, t_mlx	*mlx, int side, double rayDirX, double rayDirY, double pwd, int lineHeight);
void	draw_textures(int x, int drawStart, int drawEnd, t_mlx	*mlx, int side, double rayDirX, double rayDirY, int tex[], double pos[]);
#endif