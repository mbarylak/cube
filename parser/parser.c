/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:49:29 by mbarylak          #+#    #+#             */
/*   Updated: 2023/05/18 20:01:23 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	win_init(t_mlx *mlx)
{
	mlx->win_w = screenWidth;
	mlx->win_h = screenHeight;
	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h, "CUBE");
	mlx->addr = mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel), \
			&(mlx->line_length), &(mlx->endian));
}

void	cube_init(char *file, t_mlx *mlx)
{
	win_init(mlx);
	get_map(file, mlx);
}