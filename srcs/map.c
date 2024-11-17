/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:17:24 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/17 14:43:12 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft/libft.h"
#include "../includes/printf/ft_printf.h"
#include "../includes/MLX42/include/MLX42/MLX42.h"

char	*read_map(const char *filepath)
{
	int		fd;
	ssize_t	bytes_read;
	char	*buffer;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file"), NULL);
	buffer = malloc(10000);
	if (!buffer)
		return (perror("Memory allocation failed"), close(fd), NULL);
	bytes_read = read(fd, buffer, 9999);
	if (bytes_read < 0)
		return (perror("Error reading file"), free(buffer), close(fd), NULL);
	buffer[bytes_read] = '\0';
	return (close(fd), buffer);
}

static char	parse_map_logic(char *map_string,
							int row,
							char *line_start,
							char **map)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	while (map_string[i++])
	{
		if (map_string[i] == '\n' || map_string[i + 1] == '\0')
		{
			if (map_string[i + 1] == '\0')
				len = (&map_string[i] - line_start) + 1;
			else
				len = &map_string[i] - line_start;
			map[row] = malloc(len + 1);
			if (!map[row])
				return (perror("Memory allocation failed"), -1);
			j = 0;
			while (j++ < len)
				map[row][j] = line_start[j];
			map[row][len] = '\0';
			row++;
			line_start = &map_string[i + 1];
		}
	}
	return (1);
}

char	**parse_map(char *map_string)
{
	int		lines;
	char	**map;
	int		row;
	char	*line_start;

	row = 0;
	lines = 0;
	while (map_string[row++])
		if (map_string[row] == '\n')
			lines++;
	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
	{
		perror("Memory allocation failed");
		free(map_string);
		exit(EXIT_FAILURE);
	}
	row = 0;
	line_start = map_string;
	if (!(parse_map_logic(map_string, row, line_start, map)))
		return (NULL);
	map[row] = NULL;
	return (map);
}

static int	validate_logic(int rows, int cols, char **map)
{
	int		x;
	int		y;
	int		has_everything;
	char	c;

	y = 0;
	has_everything = 0;
	while (y++ < rows)
	{
		x = 0;
		while (x++ < cols)
		{
			c = map[y][x];
			if ((y == 0 || y == rows - 1 || x == 0 || x == cols - 1)
				&& c != '1')
			{
				perror("Map is not surrounded by walls");
				exit(EXIT_FAILURE);
			}
			if (c == 'P' || c == 'E' || c == 'C')
				has_everything++;
		}
	}
	return (has_everything);
}

void	validate_map(char **map)
{
	int		rows;
	int		cols;
	int		has_everything;

	rows = 0;
	cols = 0;
	while (map[rows])
	{
		if (cols == 0)
			cols = ft_strlen(map[rows]);
		else if ((int)strlen(map[rows]) != cols)
		{
			perror("Map is not rectangular");
			exit(EXIT_FAILURE);
		}
		rows++;
	}
	has_everything = validate_logic(rows, cols, map);
	if (has_everything < 1)
	{
		perror("Map must contain at least one 'P', 'E', and 'C'");
		exit(EXIT_FAILURE);
	}
}
