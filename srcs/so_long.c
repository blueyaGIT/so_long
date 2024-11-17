/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:44:03 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/17 14:42:54 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft/libft.h"
#include "../includes/printf/ft_printf.h"
#include "../includes/MLX42/include/MLX42/MLX42.h"

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
	int			rows;

	map_string = read_map("assets/map.ber");
	if (!map_string)
		return (1);
	rows = get_num_rows("assets/map.ber");
	map = malloc(sizeof(char *) * rows);
	if (parse_map_logic(map_string, map) == -1)
	{
		free(map_string);
		free_map(map);
		return (perror("Map parsing failed"), 1);
	}
	visual.mlx = mlx_init(WINDOW_X, WINDOW_Y, "test", false);
	visual.img = mlx_new_image(visual.mlx, WINDOW_X, WINDOW_X);
	print_ui(&visual);
	mlx_image_to_window(visual.mlx, visual.img, 0, 0);
	mlx_key_hook(visual.mlx, key_press, &visual);
	mlx_image_to_window(visual.mlx, visual.img, 0, 0);
	mlx_loop(visual.mlx);
	close_window(&visual);
	return (0);
}
