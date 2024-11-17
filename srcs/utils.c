/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:04:12 by dalbano           #+#    #+#             */
/*   Updated: 2024/11/17 14:35:45 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MLX42/include/MLX42/MLX42.h"
#include "../includes/libft/libft.h"
#include "../includes/printf/ft_printf.h"
#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i++])
		free(map[i]);
	free(map);
}

int	get_num_rows(const char *filename)
{
	int		fd;
	char	buffer[1024];
	int		rows;
	ssize_t	bytes_read;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening map file");
		return (-1);
	}
	rows = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		i = 0;
		while (i++ < bytes_read)
			if (buffer[i] == '\n')
				rows++;
	}
	close(fd);
	return (rows);
}
