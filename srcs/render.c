/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:57:01 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/17 14:04:08 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft/libft.h"
#include "../includes/printf/ft_printf.h"
#include "../includes/MLX42/include/MLX42/MLX42.h"

#define TILE_SIZE 32

void	render_map(char **map, void *mlx, void *win, void **textures)
{
	void	*img;
	int		x;
	int		y;

	y = 0;
	while (map[y++])
	{
		x = 0;
		while (map[y][x++])
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
			mlx_put_image_to_window(mlx, win, img, x * TILE_SIZE, y
				* TILE_SIZE);
		}
	}
}
