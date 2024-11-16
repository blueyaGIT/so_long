/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:58:10 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/16 17:00:26 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft/libft.h"
#include "../includes/printf/ft_printf.h"
#include "../includes/MLX42/include/MLX42/MLX42.h"

void	key_pres_julia(t_visual *visual, mlx_key_data_t key_data)
{
	if (key_data.key == MLX_KEY_W)
		visual->px->cb += 0.0002;
	if (key_data.key == MLX_KEY_S)
		visual->px->cb -= 0.0002;
	if (key_data.key == MLX_KEY_A)
		visual->px->ca -= 0.0002;
	if (key_data.key == MLX_KEY_D)
		visual->px->ca += 0.0002;
	loop_img_julia(visual);
}

void	key_rgb(t_visual *visual, mlx_key_data_t key_data)
{
	int	x;

	x = 1;
	if (mlx_is_key_down(visual->mlx, MLX_KEY_LEFT_SHIFT)
		|| mlx_is_key_down(visual->mlx, MLX_KEY_RIGHT_SHIFT))
		x *= -1;
	if (key_data.key == MLX_KEY_R)
		visual->r += x;
	else if (key_data.key == MLX_KEY_B)
		visual->b += x;
	else if (key_data.key == MLX_KEY_G)
		visual->g += x;
	ft_printf("R = %d\nG = %d\nB = %d\n", visual->r, visual->g, visual->b);
	ft_printf("=======\n");
}

void	key_iterations(t_visual *visual, mlx_key_data_t key_data)
{
	int	x;

	x = 1;
	if (mlx_is_key_down(visual->mlx, MLX_KEY_LEFT_SHIFT)
		|| mlx_is_key_down(visual->mlx, MLX_KEY_RIGHT_SHIFT))
		x = 10;
	if (key_data.key == MLX_KEY_KP_SUBTRACT)
		visual->iterations -= 10 / x;
	else if (key_data.key == MLX_KEY_KP_ADD)
		visual->iterations += 10 / x;
	if (visual->iterations < 0)
	{
		visual->iterations = 0;
		ft_printf("WARNING: Iterations cannot be less than 0\n");
	}
	ft_printf("ITERATIONS = %d\n", visual->iterations);
	ft_printf("=======\n");
}

void	key_move(t_visual *visual, mlx_key_data_t key_data)
{
	double	x;

	x = 1;
	if (mlx_is_key_down(visual->mlx, MLX_KEY_LEFT_SHIFT)
		|| mlx_is_key_down(visual->mlx, MLX_KEY_RIGHT_SHIFT))
		x = 0.1;
	if (key_data.key == MLX_KEY_DOWN)
		visual->slong->horizontal_shift += (0.1 * x);
	if (key_data.key == MLX_KEY_UP)
		visual->slong->horizontal_shift -= (0.1 * x);
	if (key_data.key == MLX_KEY_LEFT)
		visual->slong->vertical_shift -= (0.1 * x);
	if (key_data.key == MLX_KEY_RIGHT)
		visual->slong->vertical_shift += (0.1 * x);
}

void	key_pres(mlx_key_data_t key_data, void *data)
{
	t_visual	*visual;

	if (key_data.action != MLX_PRESS && key_data.action != MLX_REPEAT)
		return ;
	visual = (t_visual *)data;
	if (key_data.key == MLX_KEY_ESCAPE)
		close_window(data);
	if (key_data.key == MLX_KEY_KP_ADD || key_data.key == MLX_KEY_KP_SUBTRACT)
		key_iterations((t_visual *)data, key_data);
	if (key_data.key == MLX_KEY_R || key_data.key == MLX_KEY_G
		|| key_data.key == MLX_KEY_B)
		key_rgb((t_visual *)data, key_data);
	if (key_data.key == MLX_KEY_UP || key_data.key == MLX_KEY_DOWN
		|| key_data.key == MLX_KEY_LEFT || key_data.key == MLX_KEY_RIGHT)
		key_move((t_visual *)data, key_data);
	if (visual->set == MANDELBROT)
		loop_img_mandelbrot(visual);
	else if (visual->set == JULIA)
		key_pres_julia(visual, key_data);
	else
		loop_img_buringship(visual);
}
