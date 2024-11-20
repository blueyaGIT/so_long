/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:58:10 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/20 16:21:53 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_press(mlx_key_data_t key_data, void *data)
{
	t_visual	*visual;

	if (key_data.action != MLX_PRESS && key_data.action != MLX_REPEAT)
		return ;
	visual = (t_visual *)data;
	if (key_data.key == MLX_KEY_ESCAPE)
		close_window(data);
	if (key_data.key == MLX_KEY_UP || key_data.key == MLX_KEY_DOWN
		|| key_data.key == MLX_KEY_LEFT || key_data.key == MLX_KEY_RIGHT)
		key_move((t_visual *)data, key_data);
}

void	key_move(t_visual *visual, mlx_key_data_t key_data)
{
	if (key_data.key == MLX_KEY_RIGHT)
		visual->slong->x += 1;
	else if (key_data.key == MLX_KEY_LEFT)
		visual->slong->x -= 1;
	else if (key_data.key == MLX_KEY_UP)
		visual->slong->y -= 1;
	else if (key_data.key == MLX_KEY_DOWN)
		visual->slong->y += 1;
}
