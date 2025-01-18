/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:04:12 by dalbano           #+#    #+#             */
/*   Updated: 2025/01/08 16:23:04 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_success(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->map[game->player_pos.x][game->player_pos.y] == 'E'
		&& game->num_coins == 0)
		end_game(game);
}

int	exit_mlx(t_game *game)
{
	free_map(&game->map);
	exit(1);
}

void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i] != NULL)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

void	end_game(t_game *game)
{
	mlx_delete_image(game->mlx, game->image.coin);
	mlx_delete_image(game->mlx, game->image.exit);
	mlx_delete_image(game->mlx, game->image.player);
	mlx_delete_image(game->mlx, game->image.wall);
	mlx_delete_image(game->mlx, game->image.floor);
	mlx_terminate(game->mlx);
	free_map(&game->map);
	exit(0);
}
