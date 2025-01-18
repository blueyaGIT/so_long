/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:56:04 by dalbano           #+#    #+#             */
/*   Updated: 2025/01/14 23:39:19 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_texture(t_txtr *texture)
{
	texture->exit = mlx_load_png("assets/exit.png");
	texture->player = mlx_load_png("assets/player.png");
	texture->coin = mlx_load_png("assets/coin.png");
	texture->wall = mlx_load_png("assets/wall.png");
	texture->floor = mlx_load_png("assets/floor.png");
}

void	render_texture(t_img *image, t_txtr *texture, mlx_t *mlx)
{
	image->coin = mlx_texture_to_image(mlx, texture->coin);
	image->exit = mlx_texture_to_image(mlx, texture->exit);
	image->player = mlx_texture_to_image(mlx, texture->player);
	image->wall = mlx_texture_to_image(mlx, texture->wall);
	image->floor = mlx_texture_to_image(mlx, texture->floor);
}

mlx_image_t	*texture_to_image(t_img *image, char map_char)
{
	if (map_char == '0')
		return (image->floor);
	else if (map_char == '1')
		return (image->wall);
	else if (map_char == 'E')
		return (image->exit);
	else if (map_char == 'P')
		return (image->player);
	else if (map_char == 'C')
		return (image->coin);
	else
		return (NULL);
}

void	render(t_game *game, size_t i, size_t j)
{
	mlx_image_t	*img;
	mlx_image_t	*backround_pl;

	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			img = texture_to_image(&game->image, game->map[i][j]);
			backround_pl = texture_to_image(&game->image, '0');
			mlx_resize_image(backround_pl, 50, 50);
			mlx_resize_image(img, 50, 50);
			if (img)
			{
				if (game->map[i][j] == 'P')
					mlx_image_to_window(game->mlx, backround_pl, j * 50, i
						* 50);
				mlx_image_to_window(game->mlx, img, j * 50, i * 50);
			}
			if (!img || (mlx_image_to_window(game->mlx, img, 0, 0) < 0))
				exit(1);
			j++;
		}
		i++;
	}
}

void	map_rendering(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	load_texture(&game->txtr);
	render_texture(&game->image, &game->txtr, game->mlx);
	render(game, i, j);
	delete_texture(&game->txtr);
}
