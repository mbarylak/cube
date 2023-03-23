/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:38:21 by davgarci          #+#    #+#             */
/*   Updated: 2023/03/16 16:04:04 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
void raycasting(t_mlx *mlx)
{
  int x;
  double cameraX;
  double rayDirX;
  double rayDirY;
  double deltaDistX;
	double deltaDistY;
  int mapX;
  int mapY;
  double sideDistX;
  double sideDistY;
  int stepX;
  int stepY;
  int hit; //was there a wall hit?
  int side;
  double perpWallDist;
  int lineHeight;
  int drawStart;
  int drawEnd;
  //while (1) {
    x = 0;
	  while (x < screenWidth)
	  {
        hit = 0;
        //calculate ray position and direction
        cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
        rayDirX = mlx->dirX + mlx->planeX * cameraX;
        rayDirY = mlx->dirY + mlx->planeY * cameraX;
        deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
	      deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
        mapX = (int)mlx->posX;
        mapY = (int)mlx->posY;
        if (rayDirX < 0)
        {
          stepX = -1;
          sideDistX = (mlx->posX - mapX) * deltaDistX;
        }
        else
        {
          stepX = 1;
          sideDistX = (mapX + 1.0 - mlx->posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
          stepY = -1;
          sideDistY = (mlx->posY - mapY) * deltaDistY;
        }
        else
        {
          stepY = 1;
          sideDistY = (mapY + 1.0 - mlx->posY) * deltaDistY;
        }
        while (hit == 0)
        {
          //jump to next map square, either in x-direction, or in y-direction
          if (sideDistX < sideDistY)
          {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
          }
          else
          {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
          }
          //Check if ray has hit a wall
          if (worldmap[mapX][mapY] > 0) 
            hit = 1;
        }
        if (side == 0)
          perpWallDist = (mapX - mlx->posX + (1 - stepX) / 2) / rayDirX;
	      else
		      perpWallDist = (mapY - mlx->posY + (1 - stepY) / 2) / rayDirY;
	          //data->spr.buff[x] = perpWallDist;
            
        lineHeight = (int)(screenHeight / perpWallDist);
        //calculate lowest and highest pixel to fill in current stripe
        drawStart = -lineHeight / 2 + screenHeight / 2;
        if(drawStart < 0)
          drawStart = 0;
        drawEnd = lineHeight / 2 + screenHeight / 2;
        if(drawEnd >= screenHeight)
          drawEnd = screenHeight - 1;
        vertical_texture(x, drawStart, drawEnd, mlx, side, rayDirX, rayDirY, perpWallDist, lineHeight);
        //draw_textures(x, drawStart, drawEnd, mlx, side, rayDirX, rayDirY);
        
	      x++;
	  }
    // printf("%lf %lf\n", mlx->posX, mlx->posY);
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}