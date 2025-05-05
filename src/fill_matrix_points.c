/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix_points.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:20:32 by isousa-s          #+#    #+#             */
/*   Updated: 2025/05/05 22:20:35 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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

int	fill_matrix(t_map *map, char *filename)
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
