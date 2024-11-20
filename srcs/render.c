/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:57:01 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/20 16:21:46 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define TILE_SIZE 32

void	render_map(char **map, mlx_t *mlx, void **textures)
{
	mlx_image_t	*img;
	int			x;
	int			y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				img = textures[0];
			else if (map[y][x] == '0')
				img = textures[1];
			else if (map[y][x] == 'C')
				img = textures[2];
			else if (map[y][x] == 'P')
				img = textures[3];
			else if (map[y][x] == 'E')
				img = textures[4];
			mlx_image_to_window(mlx, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
