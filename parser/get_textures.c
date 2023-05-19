/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:57:38 by mbarylak          #+#    #+#             */
/*   Updated: 2023/05/19 19:57:26 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	put_textures(t_mlx *mlx, char c, char *path)
{
	if (c == 'N')
	{
		mlx->texN.img = mlx_xpm_file_to_image(mlx->mlx, path, &mlx->x, &mlx->y);
		mlx->texN.addr = mlx_get_data_addr(mlx->texN.img, \
		&mlx->texN.bits_per_pixel, &mlx->texN.line_length, &mlx->texN.endian);
	}
	else if (c == 'S')
	{
		mlx->texS.img = mlx_xpm_file_to_image(mlx->mlx, path, &mlx->x, &mlx->y);
		mlx->texS.addr = mlx_get_data_addr(mlx->texS.img, \
		&mlx->texS.bits_per_pixel, &mlx->texS.line_length, &mlx->texS.endian);
	}
	else if (c == 'E')
	{
		mlx->texE.img = mlx_xpm_file_to_image(mlx->mlx, path, &mlx->x, &mlx->y);
		mlx->texE.addr = mlx_get_data_addr(mlx->texE.img, \
		&mlx->texE.bits_per_pixel, &mlx->texE.line_length, &mlx->texE.endian);
	}
	else if (c == 'O')
	{
		mlx->texO.img = mlx_xpm_file_to_image(mlx->mlx, path, &mlx->x, &mlx->y);
		mlx->texO.addr = mlx_get_data_addr(mlx->texO.img, \
		&mlx->texO.bits_per_pixel, &mlx->texO.line_length, &mlx->texO.endian);
	}
	return (0);
}

int	get_wall_texture(t_mlx *mlx)
{
	char	**aux;
	int		i;

	i = 0;
	aux = mlx->map.map;
	while (aux[i])
	{
		if (ft_strncmp(aux[i], "NO", 2) == 0)
			return (put_texture(mlx, 'N', aux[i]));
		else if (ft_strncmp(aux[i], "SO", 2) == 0)
			return (put_texture(mlx, 'S', aux[i]));
		else if (ft_strncmp(aux[i], "EA", 2) == 0)
			return (put_texture(mlx, 'E', aux[i]));
		else if (ft_strncmp(aux[i], 'WE', 2) == 0)
			return (put_texture(mlx, 'O', aux[i]));
		i++;
	}
	return (1);
}