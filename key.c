/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:39:54 by davgarci          #+#    #+#             */
/*   Updated: 2023/03/17 19:06:31 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



void	fdf_init(t_mlx *mlx)
{
	mlx->win_w = screenWidth;
	mlx->win_h = screenHeight;
	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h, "CUBE");
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
			&(mlx->line_length), &(mlx->endian));
	//printf("addr = %s\n", mlx->addr);
	//mlx->map.dir = dir;
	mlx->map.width = 0;
	mlx->map.height = 0;
	mlx->map.max_alt = 0;
	mlx->map.xyzc = NULL;
	mlx->multiplicator = 1;
	mlx->multi_z = 500;
	mlx->posX = 2.5; 
	mlx->posY = 3.5;  //x and y start position
	mlx->dirX = 0; 	//N [-1] 	O [0] 		E [0] 		S [1]
	mlx->dirY = -1;  	//N [0] 	O [-1] 		E [1] 		S [0]
	mlx->teta = 0;
	mlx->planeX = -0.66;	//N [0] 	O [-0.66] 	E [0.66] 	S [0]
	mlx->planeY = 0; //N [0.66] 	O [0] 		E [0] 		S [-0.66]
	mlx->x = 64;
	mlx->y = 64;
	
	mlx->texN.img = mlx_xpm_file_to_image(mlx->mlx, "./foto/pepe.xpm", &mlx->x, &mlx->y);
	mlx->texN.addr = mlx_get_data_addr(mlx->texN.img, &mlx->texN.bits_per_pixel, &mlx->texN.line_length, &mlx->texN.endian);
	mlx->texS.img = mlx_xpm_file_to_image(mlx->mlx, "./foto/42.xpm", &mlx->x, &mlx->y);
	mlx->texS.addr = mlx_get_data_addr(mlx->texS.img, &mlx->texS.bits_per_pixel, &mlx->texS.line_length, &mlx->texS.endian);
	mlx->texE.img = mlx_xpm_file_to_image(mlx->mlx, "./pics/wall_3.xpm", &mlx->x, &mlx->y);
	mlx->texE.addr = mlx_get_data_addr(mlx->texE.img, &mlx->texE.bits_per_pixel, &mlx->texE.line_length, &mlx->texE.endian);
	mlx->texO.img = mlx_xpm_file_to_image(mlx->mlx, "./pics/wall_4.xpm", &mlx->x, &mlx->y);
	mlx->texO.addr = mlx_get_data_addr(mlx->texO.img, &mlx->texO.bits_per_pixel, &mlx->texO.line_length, &mlx->texO.endian);		
	//double oldTime = 0; //time of previous frame
	//double time = 0; //time of current frame
}

int	hook_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_input(int keycode, t_mlx *mlx)
{
	printf("posX[%f] poxY[%f] dirX[%f] dirY[%f] teta[%f] planeX[%f] planeY[%f]\n", mlx->posX, mlx->posY, mlx->dirX, mlx->dirY, mlx->teta, mlx->planeX, mlx->planeY);
	if (keycode == 123) //giro derecha
	{
		double rotSpeed = 0.2;
		double oldDirX = mlx->dirX;
     	mlx->dirX = mlx->dirX * cos(rotSpeed) - mlx->dirY * sin(rotSpeed);
     	mlx->dirY = oldDirX * sin(rotSpeed) + mlx->dirY * cos(rotSpeed);
     	double oldPlaneX = mlx->planeX;
     	mlx->planeX = mlx->planeX * cos(rotSpeed) - mlx->planeY * sin(rotSpeed);
     	mlx->planeY = oldPlaneX * sin(rotSpeed) + mlx->planeY * cos(rotSpeed);
		
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
		raycasting(mlx);
	}
	if (keycode == 124) //giro izquierda
	{
		double rotSpeed = 0.2;
		double oldDirX = mlx->dirX;
     	mlx->dirX = mlx->dirX * cos(-rotSpeed) - mlx->dirY * sin(-rotSpeed);
     	mlx->dirY = oldDirX * sin(-rotSpeed) + mlx->dirY * cos(-rotSpeed);
     	double oldPlaneX = mlx->planeX;
     	mlx->planeX = mlx->planeX * cos(-rotSpeed) - mlx->planeY * sin(-rotSpeed);
     	mlx->planeY = oldPlaneX * sin(-rotSpeed) + mlx->planeY * cos(-rotSpeed);
		
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
		raycasting(mlx);
	}
			if (keycode == 0) //izq
	{
		//printf("posX %f dirX %f\n", mlx->posX, mlx->dirX);
		double moveSpeed = 1;
		if(worldmap[(int)(mlx->posX - mlx->dirY * moveSpeed)][(int)mlx->posY] == 0)
			mlx->posX -= mlx->dirY * moveSpeed;
      	if(worldmap[(int)mlx->posX][(int)(mlx->posY + mlx->dirX * moveSpeed)] == 0)
			mlx->posY += mlx->dirX * moveSpeed;
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
		raycasting(mlx);
	}
			if (keycode == 2) //dch
	{
		//printf("posX %f dirX %f\n", mlx->posX, mlx->dirX);
		double moveSpeed = 1;
		if(worldmap[(int)(mlx->posX + mlx->dirY * moveSpeed)][(int)mlx->posY] == 0)
			mlx->posX += mlx->dirY * moveSpeed;
      	if(worldmap[(int)mlx->posX][(int)(mlx->posY - mlx->dirX * moveSpeed)] == 0)
			mlx->posY -= mlx->dirX * moveSpeed;
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
		raycasting(mlx);
	}
		if (keycode == 13) //arriba
	{
		//printf("posX %f dirX %f\n", mlx->posX, mlx->dirX);
		double moveSpeed = 1;
		if(worldmap[(int)(mlx->posX + mlx->dirX * moveSpeed)][(int)mlx->posY] == 0)
			mlx->posX += mlx->dirX * moveSpeed;
      	if(worldmap[(int)mlx->posX][(int)(mlx->posY + mlx->dirY * moveSpeed)] == 0)
			mlx->posY += mlx->dirY * moveSpeed;
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
		raycasting(mlx);
	}
		if (keycode == 1) //abajo
	{
		//printf("posX %f dirX %f\n", mlx->posX, mlx->dirX);
		double moveSpeed = 1;
		if(worldmap[(int)(mlx->posX - mlx->dirX * moveSpeed)][(int)mlx->posY] == 0)
			mlx->posX -= mlx->dirX * moveSpeed;
      	if(worldmap[(int)mlx->posX][(int)(mlx->posY - mlx->dirY * moveSpeed)] == 0)
			mlx->posY -= mlx->dirY * moveSpeed;
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
		raycasting(mlx);
	}
	if (keycode == 53)
		exit(1);
	return (0);
}
