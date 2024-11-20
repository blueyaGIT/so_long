/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:43:15 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/20 16:21:23 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef enum e_set
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP,
}				t_set;

typedef struct s_player
{
	double		x;
	double		y;
	char		*so_long_name;
}				t_player;

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
	t_player	*slong;
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
void	print_ui(t_visual *visual);
void	close_window(void *param);
void	mouseaction(double a, double b, void *params);

// getch functions
void	key_move(t_visual *visual, mlx_key_data_t key_data);
void	key_press(mlx_key_data_t key_data, void *data);

// util functions
char	*read_map(const char *filepath);
char	**parse_map(char *map_string);
void	validate_map(char **map);
void	render_map(char **map, mlx_t *mlx, void **textures);
void	free_map(char **map);
int		get_num_rows(const char *filename);

#endif /* SO_LONG_H */