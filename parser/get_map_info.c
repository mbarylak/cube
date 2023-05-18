/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:54:34 by mbarylak          #+#    #+#             */
/*   Updated: 2023/05/18 20:44:41 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	get_width(char *line, t_mlx *mlx)
{
	int	width;

	if (line)
	{
		width = 0;
		while (line[width] && line[width] != '\n')
			width++;
		if (mlx->map.width < width)
			mlx->map.width = width;
	}
}

void	get_player_orientation(char c, t_mlx *mlx)
{
	if (c == 'N')
	{
		mlx->dirX = -1;
		mlx->planeY = 0.66;
	}
	else if (c == 'S')
	{
		mlx->dirX = 1;
		mlx->planeY = -0.66;
	}
	else if (c == 'E')
	{
		mlx->dirY = 1;
		mlx->planeX = 0.66;
	}
	else if (c == 'O')
	{
		mlx->dirY = -1;
		mlx->planeX = -0.66;
	}
}

int	get_player_pos(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (mlx->map.map[i])
	{
		j = 0;
		while (mlx->map.map[i][j])
		{
			if (mlx->map.map[i][j] == 'N' || mlx->map.map[i][j] == 'S' \
				|| mlx->map.map[i][j] == 'E' || mlx->map.map[i][j] == 'O')
			{
				if (i <= 0 || j <= 0)
					return (error_msg(3));
				get_player_orientation(mlx->map.map[i][j], mlx);
				mlx->posX = j + 0.5;
				mlx->posY = i + 0.5;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (error_msg(2));

}

int	get_map_info(char *file, t_mlx *mlx)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	mlx->map.width = 0;
	mlx->map.height = 0;
	if (fd < 0)
		return (error_msg(0));
	line = get_next_line(fd);
	if (!line)
		return (error_msg(1));
	get_width(line, mlx);
	while (line)
	{
		free(line);
		mlx->map.height++;
		line = get_next_line(fd);
		get_width(line, mlx);
	}
	close(fd);
	if (mlx->map.width <= 1 || mlx->map.height <= 1)
		return (error_msg(1));
	return (0);
}

void	get_map(char *file, t_mlx *mlx)
{
	int	fd;
	int	i;

	if (!get_map_info(file, mlx))
	{
		fd = open(file, O_RDONLY);
		mlx->map.map = malloc(sizeof (char *) * mlx->map.height + 1);
		if (!mlx->map.map)
			return ;
		i = 0;
		while (i < mlx->map.height)
		{
			mlx->map.map[i] = get_next_line(fd);
			i++;
		}
		mlx->map.map[i] = NULL;
		close(fd);
		get_player_pos(mlx); //esto en un futuro no puede estar aquí
	}
}
