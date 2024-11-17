/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:44:03 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/17 14:52:12 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MLX42/include/MLX42/MLX42.h"
#include "../includes/libft/libft.h"
#include "../includes/printf/ft_printf.h"
#include "../includes/so_long.h"

#define TILE_SIZE 32

void	close_window(void *param)
{
	t_visual	*visual;

	visual = (t_visual *)param;
	mlx_terminate(visual->mlx);
	exit(0);
}

void	print_ui(t_visual *visual)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = WINDOW_Y / 2;
	i = 0;
	j = 0;
	while (i++ < 10)
	{
		x = WINDOW_X / 2;
		j = 0;
		while (j++ < 10)
			mlx_put_pixel(visual->img, x++, y, 0xFF0000FF);
		y++;
	}
}

void	render_map(char **map, mlx_t *mlx, mlx_image_t *win, void **textures)
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

int	main(void)
{
	t_visual	visual;
	char		*map_string;
	char		**map;

	map_string = read_map("assets/map.ber");
	if (!map_string)
		return (1);
	map = parse_map(map_string);
	if (!map)
		return (perror("Map parsing failed"), 1);
	validate_map(map);
	free(map_string);
	visual.mlx = mlx_init(WINDOW_X, WINDOW_Y, "so_long", false);
	visual.img = mlx_new_image(visual.mlx, WINDOW_X, WINDOW_Y);
	// Load textures here and assign to visual.textures
	// Example:
	// void *textures[5];
	// textures[0] = mlx_load_png("path_to_wall.png");
	// textures[1] = mlx_load_png("path_to_floor.png");
	// textures[2] = mlx_load_png("path_to_collectible.png");
	// textures[3] = mlx_load_png("path_to_player.png");
	// textures[4] = mlx_load_png("path_to_exit.png");
	// render_map(map, visual.mlx, visual.img, textures);
	print_ui(&visual);
	mlx_image_to_window(visual.mlx, visual.img, 0, 0);
	mlx_key_hook(visual.mlx, key_press, &visual);
	mlx_loop(visual.mlx);
	close_window(&visual);
	free_map(map);
	return (0);
}
