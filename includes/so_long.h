/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:43:15 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/13 11:33:57 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "../includes/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h>
# include <string.h>

typedef enum e_set
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP,
}				t_set;

typedef struct s_so_long
{
	double		x;
	double		y;
	double		ca;
	double		cb;
	char		*so_long_name;
	double		vertical_shift;
	double		horizontal_shift;
}				t_so_long;

typedef struct s_px
{
	double		a;
	double		b;
	double		ca;
	double		cb;
	double		aa;
	double		bb;
	int			i;
}				t_px;

typedef struct s_visual
{
	t_set		set;
	t_so_long	*slong;
	t_px		*px;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			scale;
	int			iterations;
	int8_t		r;
	int8_t		g;
	int8_t		b;
}				t_visual;

# define WINDOW_X 1080
# define WINDOW_Y 720

// Implementations of ... operations

// Helper functions

#endif /* SO_LONG_H */