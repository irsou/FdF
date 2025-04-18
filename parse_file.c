/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:38:57 by isousa-s          #+#    #+#             */
/*   Updated: 2025/04/18 15:59:04 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*free_and_return(t_map *map)
{
	free(map);
	return (NULL);
}

static int	calc_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, 0);
	if (fd < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		close(fd);
		return (0);
	}
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("height: %d\n", height);
	return (height);
}

static int	calc_width(char *filename)
{
	int		width;
	int		pos_x;
	int		fd;
	char	*line;

	pos_x = 0;
	width = 0;
	fd = open(filename, 0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}

	while (line[pos_x])
	{
		while (line[pos_x] == ' ')
			pos_x++;
		if (line[pos_x] != '\0' && line[pos_x] != '\n')
			width++;
		while (line[pos_x] && line[pos_x] != ' ')
			pos_x++;
	}
	close(fd);
	printf("width: %d\n", width);
  return (width);
}

int	get_color(char *line)
{
	int	color;

	color = 0xFFFFFF;
	while (*line && *line != ' ' && *line != ',' && *line != '\n')
		line++;
	if (*line == ',')
	{
		line++;
		color = ft_hex_to_int(line);
	}
	return (color);
}

static int	fill_points(t_map *map, char *filename)
{
	int			pos_x;
	int			pos_y;
	int			pos_z;
	int			fd;
	char		*line;

	pos_x = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	while (pos_x < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break;

		pos_y = 0;
		pos_z = 0;
		while (line[pos_z] && pos_y < map->width)
		{
			while (line[pos_z] && line[pos_z] == ' ')
				pos_z++;
			if (line[pos_z] && line[pos_z] != '\n')
			{
				map->matrix[pos_x][pos_y].x = pos_y;
				map->matrix[pos_x][pos_y].y = pos_x;
				map->matrix[pos_x][pos_y].z = ft_atoi(&line[pos_z]);
				map->matrix[pos_x][pos_y].color = get_color(&line[pos_z]);
				while (line[pos_z] && line[pos_z] != ' ' && line[pos_z] != '\n')
					pos_z++;
				pos_y++;
			}
		}
		free(line);
		pos_x++;
	}
	close(fd);
	return (1);
}

t_map	*parse_file(char *filename)
{
	t_map	*map;
	int		pos;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = calc_height(filename);
	if (map->height == 0) {
		free(map);
		return (NULL);
	}
	map->width = calc_width(filename);
	if (map->width == 0) {
		free(map);
		return (NULL);
	}
	map->matrix = malloc(sizeof(t_point *) * map->height);
	if (!map->matrix) {
		free(map);
		return (NULL);
	}
	for (pos = 0; pos < map->height; pos++)
	{
		map->matrix[pos] = malloc(sizeof(t_point) * map->width);
		if (!map->matrix[pos]) {
			while (pos > 0)
				free(map->matrix[--pos]);
			free(map->matrix);
			free(map);
			return (NULL);
		}
	}
	if (!fill_points(map, filename))
	{
		for (pos = 0; pos < map->height; pos++)
			free(map->matrix[pos]);
		free(map->matrix);
		free(map);
		return (NULL);
	}
	return (map);
}