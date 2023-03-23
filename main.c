/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:30:36 by davgarci          #+#    #+#             */
/*   Updated: 2023/03/19 10:51:13 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int worldmap[mapWidth][mapHeight]=
{
 //{1,1,1,1,1,1,1},
 //{1,0,0,0,0,0,1},
 //{1,0,0,0,0,0,1},
 //{1,0,0,0,0,0,1},
 //{1,1,1,1,1,1,1}

  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int		get_tex_color(t_mlx *data, int texx, int texy, char *addr)
{
	if (texx >= 0 && texx < data->x && texy >= 0 && texy < data->y)
	{
    //printf("addr %d", *(int *)(data->texN.addr + (data->x * texy) + (texx)));
		return (*(int *)(addr + (4 * data->x * texy) + (4 * texx)));
	}
	return (0x0);
}

void	vertical_texture(int x, int drawStart, int drawEnd, t_mlx	*mlx, int side, double rayDirX, double rayDirY, double pwd, int lineHeight)
{
	double	wallx;
	int		tex[3];
	int		line_h;
	double	pos[2];
  //  printf("ENTRA:%lf\n", pwd);
	tex[2] = x;
	line_h = drawEnd - drawStart;//(int)(mlx->win_h / pwd)
	if (side == 0)
		wallx = mlx->posY + pwd * rayDirY;
	else
		wallx = mlx->posX + pwd * rayDirX;
	wallx -= floor(wallx);
	tex[0] = (int)(wallx * (double)mlx->x);
	if (side == 0 && rayDirX > 0)
		tex[0] = 64 - tex[0] - 1;
	else if (side == 1 && rayDirY < 0)
		tex[0] = 64 - tex[0] - 1;
  
  
	pos[1] = ((double)mlx->y / lineHeight);
	pos[0] = (wallx) + ((lineHeight - line_h) / 2) * pos[1];
  // printf("DIFF: real: %d, calculado: %d\n", lineHeight, line_h);
	draw_textures(x, drawStart, drawEnd, mlx, side, rayDirX, rayDirY, tex, pos);
}


void	draw_textures(int x, int drawStart, int drawEnd, t_mlx	*mlx, int side, double rayDirX, double rayDirY, int tex[], double pos[])
{
	int		i;

  (void)mlx;
	i = -1;
	while (++i < drawStart)
  {
		my_mlx_pixel_put(mlx, x, i, 0xFFFFFF); //ceiling
  }
	while (++i < drawEnd)
  {
    if (side == 0)
    {
		  if(rayDirX <  0)
      {
        tex[1] = (int)pos[0];
        pos[0] += pos[1];
        my_mlx_pixel_put(mlx, x, i, get_tex_color(mlx, tex[0], tex[1], mlx->texN.addr)); //rojo norte
      }
      else
      {
        tex[1] = (int)pos[0];
        pos[0] += pos[1];
        my_mlx_pixel_put(mlx, x, i, get_tex_color(mlx, tex[0], tex[1], mlx->texS.addr)); //verde sur
      }
    }
    else
		{
      if(rayDirY <  0)
      {
        tex[1] = (int)pos[0];
        pos[0] += pos[1];
        my_mlx_pixel_put(mlx, x, i, get_tex_color(mlx, tex[0], tex[1], mlx->texO.addr)); //blue Oeste
      }
      else
      {
        tex[1] = (int)pos[0];
        pos[0] += pos[1];
        my_mlx_pixel_put(mlx, x, i, get_tex_color(mlx, tex[0], tex[1], mlx->texE.addr)); //marron Este
      }
    }
  }
	while (++i < screenHeight)
  {
		my_mlx_pixel_put(mlx, x, i, 0); //floor
  }
}

int	main()
{
	
  t_mlx	mlx;
  
  fdf_init(&mlx);  
  raycasting(&mlx);
  
 
	//mlx_key_hook(mlx.win, ft_input, &mlx);
  mlx_hook(mlx.win, 2, 1L << 0, ft_input, &mlx);
	//mlx_hook(data->win_ptr, 3, 1L << 1, key_released, data);
	mlx_hook(mlx.win, 17, 0, hook_exit, &mlx);
	mlx_loop(mlx.mlx);
	
	return (0);
}
