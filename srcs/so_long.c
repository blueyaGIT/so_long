/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:44:03 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/17 16:08:11 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft/libft.h"
#include "../includes/printf/ft_printf.h"
#include "../includes/MLX42/include/MLX42/MLX42.h"

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

int	main(void)
{
	t_visual	visual;
	char		*map_string;
	char		**map;
	void		*textures[5];

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
	textures[0] = mlx_load_png("assets/wall.png");
	textures[1] = mlx_load_png("assets/floor.png");
	textures[2] = mlx_load_png("assets/collectible.png");
	textures[3] = mlx_load_png("assets/player.png");
	textures[4] = mlx_load_png("assets/exit.png");
	render_map(map, visual.mlx, textures);
	print_ui(&visual);
	mlx_image_to_window(visual.mlx, visual.img, 0, 0);
	mlx_key_hook(visual.mlx, key_press, &visual);
	mlx_loop(visual.mlx);
	close_window(&visual);
	free_map(map);
	return (0);
}
