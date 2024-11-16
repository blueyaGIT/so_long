/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:17:24 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/16 16:42:53 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft/libft.h"
#include "../includes/printf/ft_printf.h"
#include "../includes/MLX42/include/MLX42/MLX42.h"

void	mouseaction(double a, double b, void *params)
{
	double		multiplier;
	t_visual	*visual;

	(void)a;
	visual = (t_visual *)params;
	if (mlx_is_key_down(visual->mlx, MLX_KEY_LEFT_SHIFT)
		|| mlx_is_key_down(visual->mlx, MLX_KEY_RIGHT_SHIFT))
		return ;
	if (b > 0)
		multiplier = 1.1;
	else
		multiplier = 0.9;
	visual->scale *= multiplier;
	if (visual->set == MANDELBROT)
		loop_img_mandelbrot(visual);
	else if (visual->set == JULIA)
		loop_img_julia(visual);
	else
		loop_img_buringship(visual);
}
