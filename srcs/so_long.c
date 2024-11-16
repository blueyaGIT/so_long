/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:44:03 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/16 16:44:06 by dalbano          ###   ########.fr       */
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

	visual.mlx = mlx_init(WINDOW_X, WINDOW_Y, "test", false);
	visual.img = mlx_new_image(visual.mlx, WINDOW_X, WINDOW_X);
	print_ui(&visual);
	mlx_image_to_window(visual.mlx, visual.img, 0, 0);
	mlx_scroll_hook(visual.mlx, mouseaction, &visual);
	mlx_key_hook(visual.mlx, key_pres, &visual);
	mlx_image_to_window(visual.mlx, visual.img, 0, 0);
	mlx_loop(visual.mlx);
	close_window(&visual);
	return (0);
}
