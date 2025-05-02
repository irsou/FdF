/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:38:57 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/02 22:28:22 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

static int	count_elements(char *line)
{
	int		width;
	int		pos;

	width = 0;
	pos = 0;
	while (line[pos])
	{
		while (line[pos] == ' ')
			pos++;
		if (line[pos] != '\0' && line[pos] != '\n')
		{
			width++;
			while (line[pos] && line[pos] != ' ' && line[pos] != '\n')
				pos++;
		}
		else
			break ;
	}
	return (width);
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
	width = count_elements(line);
	free(line);
	close(fd);
	return (width);
}

int	get_color(char *line)
{
	int	color;

	color = 0x24F9DC;
	while (*line && *line != ' ' && *line != ',' && *line != '\n')
		line++;
	if (*line == ',')
	{
		line++;
		color = ft_hex_to_int(line);
	}
	return (color);
}

static void	process_point(t_map *map, int x, int y, char *segment)
{
	map->matrix[x][y].x = y;
	map->matrix[x][y].y = x;
	map->matrix[x][y].z = ft_atoi(segment);
	map->matrix[x][y].color = get_color(segment);
}

static void	fill_empty_point(t_map *map, int x, int y)
{
	map->matrix[x][y].x = y;
	map->matrix[x][y].y = x;
	map->matrix[x][y].z = 0;
	map->matrix[x][y].color = 0x24F9DC;
}

static void	handle_extra_elements(int *warning)
{
	if (!(*warning))
	{
		write(2,
			"Line has more elements than expected. Extra elements ignored.\n",
			63);
		*warning = 1;
	}
}

static void	fill_remaining_points(t_map *map, int pos_x, int *pos_y)
{
	write(2,
		"Line has fewer elements than expected. Filling with zeros.\n", 60);
	while (*pos_y < map->width)
	{
		fill_empty_point(map, pos_x, *pos_y);
		(*pos_y)++;
	}
}

static void	process_line_elements(t_map *map, char *line, int pos_x, int *pos_y)
{
	int		pos_z;
	int		warning;

	pos_z = 0;
	warning = 0;
	while (line[pos_z])
	{
		while (line[pos_z] && line[pos_z] == ' ')
			pos_z++;
		if (line[pos_z] && line[pos_z] != '\n')
		{
			if (*pos_y < map->width)
				process_point(map, pos_x, *pos_y, &line[pos_z]);
			else
				handle_extra_elements(&warning);
			while (line[pos_z] && line[pos_z] != ' ' && line[pos_z] != '\n')
				pos_z++;
			(*pos_y)++;
		}
		else
			break ;
	}
}

static int	process_line(t_map *map, char *line, int pos_x)
{
	int	pos_y;

	pos_y = 0;
	process_line_elements(map, line, pos_x, &pos_y);
	if (pos_y < map->width)
		fill_remaining_points(map, pos_x, &pos_y);
	return (1);
}

static int	fill_points(t_map *map, char *filename)
{
	int		pos_x;
	int		fd;
	char	*line;

	pos_x = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (pos_x < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		process_line(map, line, pos_x++);
		free(line);
	}
	close(fd);
	return (1);
}

void	free_matrix(t_map *map)
{
	int		pos;

	pos = 0;
	while (pos < map->height)
	{
		free(map->matrix[pos]);
		pos++;
	}
	free(map->matrix);
	free(map);
}

t_map	*init_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = calc_height(filename);
	map->width = calc_width(filename);
	if (map->height == 0 || map->width == 0)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

int	allocate_matrix(t_map *map)
{
	int	pos;

	map->matrix = malloc(sizeof(t_point *) * map->height);
	if (!map->matrix)
	{
		free(map);
		return (0);
	}
	pos = 0;
	while (pos < map->height)
	{
		map->matrix[pos] = malloc(sizeof(t_point) * map->width);
		if (!map->matrix[pos])
		{
			free_matrix(map);
			return (0);
		}
		pos++;
	}
	return (1);
}

t_map	*parse_file(char *filename)
{
	t_map	*map;

	map = init_map(filename);
	if (!map)
		return (NULL);
	if (!allocate_matrix(map))
		return (NULL);
	if (!fill_points(map, filename))
	{
		free_matrix(map);
		return (NULL);
	}
	return (map);
}
