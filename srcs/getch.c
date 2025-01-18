/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:58:10 by dalbano           #+#    #+#             */
/*   Updated: 2025/01/15 00:47:19 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	getch(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		free_map(&game->map);
		exit(0);
	}
	else if (key.key == MLX_KEY_UP && key.action == MLX_PRESS
		&& game->map[game->player_pos.x
			- 1][game->player_pos.y] != '1')
		move_north(game);
	else if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS
		&& game->map[game->player_pos.x
			+ 1][game->player_pos.y] != '1')
		move_south(game);
	else if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS
		&& game->map[game->player_pos.x][game->player_pos.y
		+ 1] != '1')
		move_east(game);
	else if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS
		&& game->map[game->player_pos.x][game->player_pos.y
		- 1] != '1')
		move_west(game);
}

void	move_north(t_game *game)
{
	if (game->map[game->player_pos.x][game->player_pos.y] == 'E')
	{
		mlx_image_to_window(game->mlx, game->image.exit, game->player_pos.y
			* 50, game->player_pos.x * 50);
		game->player_pos.x--;
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image.floor,
			game->player_pos.y * 50, game->player_pos.x * 50);
		game->player_pos.x--;
	}
	if (game->map[game->player_pos.x][game->player_pos.y] == 'C')
	{
		game->num_coins--;
		mlx_image_to_window(game->mlx, game->image.floor,
			game->player_pos.y * 50, game->player_pos.x * 50);
		game->map[game->player_pos.x][game->player_pos.y] = '0';
	}
	mlx_image_to_window(game->mlx, game->image.player, game->player_pos.y
		* 50, game->player_pos.x * 50);
	game->move_count++;
	ft_printf("moved NORTH. total moves: %d\n", game->move_count);
}

void	move_south(t_game *game)
{
	if (game->map[game->player_pos.x][game->player_pos.y] == 'E')
	{
		mlx_image_to_window(game->mlx, game->image.exit, game->player_pos.y
			* 50, game->player_pos.x * 50);
		game->player_pos.x++;
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image.floor,
			game->player_pos.y * 50, game->player_pos.x * 50);
		game->player_pos.x++;
	}
	if (game->map[game->player_pos.x][game->player_pos.y] == 'C')
	{
		game->num_coins--;
		mlx_image_to_window(game->mlx, game->image.floor,
			game->player_pos.y * 50, game->player_pos.x * 50);
		game->map[game->player_pos.x][game->player_pos.y] = '0';
	}
	mlx_image_to_window(game->mlx, game->image.player, game->player_pos.y
		* 50, game->player_pos.x * 50);
	game->move_count++;
	ft_printf("moved SOUTH. total moves: %d\n", game->move_count);
}

void	move_east(t_game *game)
{
	if (game->map[game->player_pos.x][game->player_pos.y] == 'E')
	{
		mlx_image_to_window(game->mlx, game->image.exit, game->player_pos.y
			* 50, game->player_pos.x * 50);
		game->player_pos.y++;
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image.floor,
			game->player_pos.y * 50, game->player_pos.x * 50);
		game->player_pos.y++;
	}
	if (game->map[game->player_pos.x][game->player_pos.y] == 'C')
	{
		game->num_coins--;
		mlx_image_to_window(game->mlx, game->image.floor,
			game->player_pos.y * 50, game->player_pos.x * 50);
		game->map[game->player_pos.x][game->player_pos.y] = '0';
	}
	mlx_image_to_window(game->mlx, game->image.player, game->player_pos.y
		* 50, game->player_pos.x * 50);
	game->move_count++;
	ft_printf("moved EAST. total moves: %d\n", game->move_count);
}

void	move_west(t_game *game)
{
	if (game->map[game->player_pos.x][game->player_pos.y] == 'E')
	{
		mlx_image_to_window(game->mlx, game->image.exit, game->player_pos.y
			* 50, game->player_pos.x * 50);
		game->player_pos.y--;
	}
	else
	{
		mlx_image_to_window(game->mlx, game->image.floor,
			game->player_pos.y * 50, game->player_pos.x * 50);
		game->player_pos.y--;
	}
	if (game->map[game->player_pos.x][game->player_pos.y] == 'C')
	{
		game->num_coins--;
		mlx_image_to_window(game->mlx, game->image.floor,
			game->player_pos.y * 50, game->player_pos.x * 50);
		game->map[game->player_pos.x][game->player_pos.y] = '0';
	}
	mlx_image_to_window(game->mlx, game->image.player, game->player_pos.y
		* 50, game->player_pos.x * 50);
	game->move_count++;
	ft_printf("moved WEST. total moves: %d\n", game->move_count);
}
