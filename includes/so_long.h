/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:43:15 by dalbano           #+#    #+#             */
/*   Updated: 2025/01/18 23:16:51 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SIZE 50

typedef struct s_pos
{
	size_t			x;
	size_t			y;
}					t_pos;

typedef struct s_txtr
{
	mlx_texture_t	*coin;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
}					t_txtr;

typedef struct s_img
{
	mlx_image_t		*coin;
	mlx_image_t		*exit;
	mlx_image_t		*player;
	mlx_image_t		*wall;
	mlx_image_t		*floor;

}					t_img;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int				maplines;
	int				fd;
	char			*line;
	char			*map_string;
	char			*tmp;
	int				width;
	int				height;
	int				leng;
	int				num_coins;
	int				move_count;
	t_txtr			txtr;
	t_pos			player_pos;
	t_img			image;
}					t_game;

# define WINDOW_X 1080
# define WINDOW_Y 720
# define TILE_SIZE 32

// game functions
void				check_success(void *param);
int					exit_mlx(t_game *game);

// getch functions
void				getch(mlx_key_data_t key, void *param);
void				move_north(t_game *game);
void				move_south(t_game *game);
void				move_east(t_game *game);
void				move_west(t_game *game);

// map functions
void				free_map(char ***map);
void				load_texture(t_txtr *texture);
void				render_texture(t_img *image, t_txtr *texture, mlx_t *mlx);
void				render(t_game *game, size_t i, size_t j);
void				map_rendering(t_game *game);
mlx_image_t			*texture_to_image(t_img *image, char map_char);
bool				exit_valid(t_game *game);
bool				player_valid(t_game *game);
bool				coin_valid(t_game *game);
void				map_valid(t_game *game);
void				map_valid_2(t_game *game);
bool				checking_false_chars(t_game *game);
bool				top_wall(t_game *game);
bool				bottom_wall(t_game *game);
bool				left_wall(t_game *game);
bool				right_wall(t_game *game);
void				tile_check(char **map, int x, int y);
char				**copy_map(char **map);
bool				find_player_pos(char **map, int *player_x, int *player_y);
bool				check_access(char **map_copy, char **original_map);
bool				valid_map_access(t_game *game);
void				validate_map(char *map_string);
char				*read_lines(int fd);
void				free_all(char *line, char *map_string, int fd);
int					open_file(char *path);
bool				nl_valid(char *mapstring);

// util functions
void				end_game(t_game *game);
void				delete_texture(t_txtr *texture);
void				reading_map(t_game *game, char *path);
void				path_name_checker(char *path);
void				split_map(t_game *game, char *map_string);
void				game_success(t_game *game);

#endif /* SO_LONG_H */