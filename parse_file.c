/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:38:57 by isousa-s          #+#    #+#             */
/*   Updated: 2025/03/22 22:16:27 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*free_and_return(t_map *map)
{
	free(map);
	return (NULL);
}

static int calc_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, 0);
	if (fd < 0)
		return (0);
	height = 0;
	while (line = get_next_line(fd))
	{
		height++;
		free(line);
	}
	close(fd);
	printf("height: %d\n", height);
	return (height);
}

static int calc_width(char *line)
{
	int		width;
	int		pos_x;

	width = 0;
	pos_x = 0;
	while (line[pos_x])
	{
		while (line[pos_x] && line[pos_x] == ' ')
			pos_x++;
		if (line[pos_x])
			width++;
		while (line[pos_x] && line[pos_x] == ' ')
			pos_x++;
	}
	printf("width: %d\n", width);
	return (width);
}

static int fill_points(t_map *map, int fd)
{
	int		pos_x;
	int		pos_y;
	int		pos_z;
	char	*line;

	pos_x = 0;
	while ((line = get_next_line(fd)) && pos_x < map->height)
	{
		pos_y = 0;
		pos_z = 0;
		while (line[pos_z] && pos_y < map->width)
		{
			while (line[pos_z] && line[pos_z] == ' ')
				pos_z++;
			if(line[pos_z])
			{
				map->matrix[pos_x][pos_y].x = pos_y;
				map->matrix[pos_x][pos_y].y = pos_x;
				map->matrix[pos_x][pos_y].z = ft_atoi(&line[pos_z]);
				pos_y++;
			}
			while (line[pos_z] && line[pos_z] != ' ')
			pos_z++;
			}
			free(line);
			pos_x++;
	}
	return (1);
}

t_map	*parse_file(char *filename)
{
	t_map	*map;
	int		fd;
	int		pos;
	char	*line;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = calc_height(filename);
	fd = open(filename, 0);
	if (fd < 0)
	{
		write(1, "Error al abrir archivo\n", 23);
		return (free_and_return(map));
	}
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (free_and_return(map));
	}
	map->width = calc_width(line);
	write(1, "Altura: ", 8);
	map->matrix = (t_point **)malloc(sizeof(t_point *)*map->height);
	if (!map->matrix)
		return (free_and_return(map));
	pos = 0;
	while (pos < (map->height))
	{
		map->matrix[pos] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->matrix[pos])
		{
			while (pos >0)
				free(map->matrix[--pos]);
			free(map->matrix);
			free(map);
			return (NULL);
		}
		pos++;
	}
	fd = open(filename, 0);
	if (fd < 0)
		return (free_and_return(map));
	fill_points(map, fd);
	close(fd);
	return (map);
}