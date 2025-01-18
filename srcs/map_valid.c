/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:16:25 by dalbano           #+#    #+#             */
/*   Updated: 2025/01/14 20:20:48 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	exit_valid(t_game *game)
{
	int	e_found;
	int	i;
	int	j;

	e_found = 0;
	i = 0;
	j = 1;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				e_found++;
			j++;
		}
		i++;
	}
	if (e_found != 1)
		return (false);
	return (true);
}

bool	player_valid(t_game *game)
{
	int	p_found;
	int	i;
	int	j;

	p_found = 0;
	i = 0;
	j = 1;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_pos.x = i;
				game->player_pos.y = j;
				p_found++;
			}
			j++;
		}
		i++;
	}
	if (p_found != 1)
		return (false);
	return (true);
}

bool	coin_valid(t_game *game)
{
	int	c_found;
	int	i;
	int	j;

	c_found = 0;
	i = 0;
	j = 1;
	while (game->map && game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				c_found++;
			j++;
		}
		i++;
	}
	game->num_coins = c_found;
	if (c_found < 1)
		return (false);
	return (true);
}

void	map_valid(t_game *game)
{
	if (!left_wall(game))
	{
		ft_putstr_fd("Error: left_wall\n", 2);
		exit_mlx(game);
	}
	if (!right_wall(game))
	{
		ft_putstr_fd("Error: right_wall\n", 2);
		exit_mlx(game);
	}
	if (!bottom_wall(game))
	{
		ft_putstr_fd("Error: bottow_wall\n", 2);
		exit_mlx(game);
	}
	if (!top_wall(game))
	{
		ft_putstr_fd("Error: top_wall\n", 2);
		exit_mlx(game);
	}
	map_valid_2(game);
}

void	map_valid_2(t_game *game)
{
	if (!coin_valid(game))
	{
		ft_putstr_fd("Error: Coins\n", 2);
		exit_mlx(game);
	}
	if (!player_valid(game))
	{
		ft_putstr_fd("Error: Player\n", 2);
		exit_mlx(game);
	}
	if (!exit_valid(game))
	{
		ft_putstr_fd("Error: Exit\n", 2);
		exit_mlx(game);
	}
	if (!valid_map_access(game))
	{
		ft_putstr_fd("Error: Map not accessible\n", 2);
		exit_mlx(game);
	}
	if (!checking_false_chars(game))
	{
		ft_putstr_fd("Error: Wrong chars\n", 2);
		exit_mlx(game);
	}
}