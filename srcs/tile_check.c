/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:27:44 by dalbano           #+#    #+#             */
/*   Updated: 2025/01/14 19:32:36 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	tile_check(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0'
		|| map[y][x] == '1')
		return ;
	if (map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	tile_check(map, x + 1, y);
	tile_check(map, x - 1, y);
	tile_check(map, x, y + 1);
	tile_check(map, x, y - 1);
}

char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i] != NULL)
		i++;
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(&copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

bool	find_player_pos(char **map, int *player_x, int *player_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				*player_x = x;
				*player_y = y;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

bool	check_access(char **map_copy, char **original_map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (original_map[y] != NULL)
	{
		x = 0;
		while (original_map[y][x] != '\0')
		{
			if ((original_map[y][x] == 'C' || original_map[y][x] == 'E')
				&& map_copy[y][x] != 'F')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	valid_map_access(t_game *game)
{
	char	**map_copy;
	int		player_x;
	int		player_y;

	player_x = -1;
	player_y = -1;
	map_copy = copy_map(game->map);
	if (!map_copy)
		return (false);
	if (!find_player_pos(game->map, &player_x, &player_y))
	{
		free_map(&map_copy);
		return (false);
	}
	tile_check(map_copy, player_x, player_y);
	if (!check_access(map_copy, game->map))
	{
		free_map(&map_copy);
		return (false);
	}
	free_map(&map_copy);
	return (true);
}
