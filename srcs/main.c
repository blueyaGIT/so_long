/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:44:03 by dalbano           #+#    #+#             */
/*   Updated: 2025/02/03 16:47:26 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.move_count = 0;
	if (argc != 2)
		return (ft_putstr_fd("Error wrong input\n", 2), 1);
	argc = 0;
	reading_map(&game, argv[1]);
	map_valid(&game);
	game.mlx = mlx_init(game.width * SIZE, game.height * SIZE, "so_long",
			true);
	if (!game.mlx)
		exit_mlx(&game);
	map_rendering(&game);
	mlx_key_hook(game.mlx, &getch, &game);
	mlx_loop_hook(game.mlx, &check_success, &game);
	mlx_loop(game.mlx);
	game_success(&game);
	return (0);
}
